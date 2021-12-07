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

#ifndef TCAM_V4L2_UTILS_H
#define TCAM_V4L2_UTILS_H

#include "../DeviceInfo.h"
#include "../compiler_defines.h"

#include <vector>

VISIBILITY_INTERNAL

namespace tcam
{

namespace v4l2
{

TCAM_PROPERTY_TYPE v4l2_property_type_to_tcam(uint32_t type);

} /* namespace v4l2 */


/**
 * @name get_v4l2_device_list
 * @brief lists all supported v4l2 devices
 * @return vector containing all found v4l2 devices
 */
std::vector<DeviceInfo> get_v4l2_device_list();

} /* namespace tcam */

VISIBILITY_POP

#endif /* TCAM_V4L2_UTILS_H */
