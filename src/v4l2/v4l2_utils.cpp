/*
 * Copyright 2014 The Imaging Source Europe GmbH
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "v4l2_utils.h"

#include "../logging.h"
#include "../utils.h"

#if HAVE_UDEV
#include <libudev.h>
#endif

#include <glob.h>

#include <linux/videodev2.h>

using namespace tcam;

TCAM_PROPERTY_TYPE tcam::v4l2::v4l2_property_type_to_tcam(uint32_t type)
{
    switch (type)
    {
        case V4L2_CTRL_TYPE_BOOLEAN:
        {
            return TCAM_PROPERTY_TYPE_BOOLEAN;
        }
        case V4L2_CTRL_TYPE_INTEGER:
        {
            return TCAM_PROPERTY_TYPE_INTEGER;
        }
        case V4L2_CTRL_TYPE_STRING:
        {
            return TCAM_PROPERTY_TYPE_STRING;
        }
        case V4L2_CTRL_TYPE_INTEGER_MENU:
        case V4L2_CTRL_TYPE_MENU:
        {
            return TCAM_PROPERTY_TYPE_ENUMERATION;
        }
        case V4L2_CTRL_TYPE_BUTTON:
        {
            return TCAM_PROPERTY_TYPE_BUTTON;
        }
        default:
        {
            return TCAM_PROPERTY_TYPE_UNKNOWN;
        }
    }
}


std::vector<DeviceInfo> tcam::get_v4l2_device_list()
{
    std::vector<DeviceInfo> device_list;

    struct udev* udev = udev_new();
    if (!udev)
    {
        return device_list;
    }

    /* Create a list of the devices in the 'video4linux' subsystem. */
    struct udev_enumerate* enumerate = udev_enumerate_new(udev);
    udev_enumerate_add_match_subsystem(enumerate, "video4linux");
    udev_enumerate_scan_devices(enumerate);
    struct udev_list_entry* devices = udev_enumerate_get_list_entry(enumerate);
    struct udev_list_entry* dev_list_entry;

    auto device_is_known = [&device_list](const DeviceInfo& info) {
        for (const auto& dev : device_list)
        {
            if (dev.get_serial() == info.get_serial())
            {
                return true;
            }
        }
        return false;
    };

    udev_list_entry_foreach(dev_list_entry, devices)
    {
        const char* path;
        char needed_path[100];

        /* Get the filename of the /sys entry for the device
           and create a udev_device object (dev) representing it */
        path = udev_list_entry_get_name(dev_list_entry);
        struct udev_device* dev = udev_device_new_from_syspath(udev, path);

        /* The device pointed to by dev contains information about
           the hidraw device. In order to get information about the
           USB device, get the parent device with the
           subsystem/devtype pair of "usb"/"usb_device". This will
           be several levels up the tree, but the function will find
           it.*/

        /* we need to copy the devnode (/dev/videoX) before the path
           is changed to the path of the usb device behind it (/sys/class/....) */
        strcpy(needed_path, udev_device_get_devnode(dev));

        struct udev_device* parent_device =
            udev_device_get_parent_with_subsystem_devtype(dev, "usb", "usb_device");

        /* skip this device if we can't get the usb parent */
        if (!parent_device)
        {
            udev_device_unref(dev);
            continue;
        }

        /* From here, we can call get_sysattr_value() for each file
           in the device's /sys entry. The strings passed into these
           functions (idProduct, idVendor, serial, etc.) correspond
           directly to the files in the directory which represents
           the USB device. Note that USB strings are Unicode, UCS2
           encoded, but the strings returned from
           udev_device_get_sysattr_value() are UTF-8 encoded. */

        static const char* TCAM_VENDOR_ID_STRING = "199e";

        if (strcmp(udev_device_get_sysattr_value(parent_device, "idVendor"), TCAM_VENDOR_ID_STRING)
            == 0)
        {
            // S-Video to USB-2.0 converter. // 199e:8002 The Imaging Source Europe GmbH DFG/USB2pro
            // Name is best option for filtering this device.
            // Support not viable. Considered legacy product since tiscamera came to be.
            if (strcmp(udev_device_get_sysattr_value(parent_device, "product"), "DFG/USB2pro") == 0)
            {
                continue;
            }
            tcam_device_info info = {};
            info.type = TCAM_DEVICE_TYPE_V4L2;
            strncpy(info.identifier, needed_path, sizeof(info.identifier));

            if (udev_device_get_sysattr_value(parent_device, "idProduct") != NULL)
            {
                strncpy(info.additional_identifier,
                        udev_device_get_sysattr_value(parent_device, "idProduct"),
                        sizeof(info.additional_identifier) - 1);
            }

            if (udev_device_get_sysattr_value(parent_device, "product") != NULL)
            {
                strncpy(info.name,
                        udev_device_get_sysattr_value(parent_device, "product"),
                        sizeof(info.name) - 1);
            }
            if (udev_device_get_sysattr_value(parent_device, "serial") != NULL)
            {
                std::string tmp = udev_device_get_sysattr_value(parent_device, "serial");
                tmp.erase(remove_if(tmp.begin(), tmp.end(), isspace), tmp.end());
                strncpy(info.serial_number, tmp.c_str(), sizeof(info.serial_number) - 1);
            }

            auto new_dev = DeviceInfo(info);
            if (!device_is_known(new_dev))
            {
                device_list.push_back(new_dev);
            }
        }

        udev_device_unref(dev);
    }

    /* Free the enumerator object */
    udev_enumerate_unref(enumerate);

    udev_unref(udev);

    return device_list;
}
