/*
 * Copyright 2019 The Imaging Source Europe GmbH
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

#include "libusb_api.h"

#include "../logging.h"
#include "AFU050Device.h"
#include "AFU420Device.h"
#include "UsbHandler.h"
#include "libusb_utils.h"

#include <cstring>


DeviceInterface* open_libusb_device(const struct tcam_device_info* device)
{
    if (strcmp(device->additional_identifier, "804") == 0)
    {
        return new AFU420Device(DeviceInfo(*device));
    }
    else if (strcmp(device->additional_identifier, "8209") == 0)
    {
        return new AFU050Device(DeviceInfo(*device));
    }
    else
    {
        SPDLOG_ERROR("Unable to identify requested LibUsb Backend %x",
                     device->additional_identifier);
        return nullptr;
    }
}


size_t get_libusb_device_list_size()
{
    auto vec = tcam::libusb::get_libusb_device_list();
    return vec.size();
}


/**
 * @return number of copied device_infos
 */
size_t get_libusb_device_list(struct tcam_device_info* array, size_t array_size)
{
    auto vec = tcam::libusb::get_libusb_device_list();

    if (vec.size() > array_size)
    {
        return 0;
    }

    for (const auto& v : vec)
    {
        auto i = v.get_info();
        memcpy(array, &i, sizeof(struct tcam_device_info));
        array++;
    }

    return vec.size();
}
