/*
   Copyright (c) 2014, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <cstdlib>
#include <fstream>
#include <string>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_msm8916.h"

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void init_target_properties()
{
    std::ifstream fin;
    std::string buf;

    fin.open("/proc/app_info");
    while (getline(fin, buf))
        if (buf.find("huawei_fac_product_name") != std::string::npos)
            break;
    fin.close();

    /* Huawei T1-A21L/21W/22L/23L */
    
    /* t1_10-All_models */
    if (buf.find("t1_10") != std::string::npos) {
        property_override("ro.product.model", "t1_10");
        property_override("ro.product.device", "t1_10");
        property_override("ro.build.product", "t1_10");
        property_set("ro.telephony.default_network", "9");
        property_override("ro.build.description", "t1_10-user 5.1.1 HuaweiMediaPad C233B117 release-keys");
        property_override("ro.build.fingerprint", "Huawei/t1_10/hwt1a21l:5.1.1/HuaweiMediaPad/T1A23LC233B117:user/release-keys");
    }
    
    /* T1-A21L */
    else if (buf.find("T1-A21L") != std::string::npos) {
        property_override("ro.product.model", "T1-A21L");
        property_override("ro.product.device", "T1-A21L");
        property_override("ro.build.product", "T1-A21L");
        property_set("ro.telephony.default_network", "9");
        property_override("ro.build.description", "t1_10-user 5.1.1 HuaweiMediaPad C233B117 release-keys");
        property_override("ro.build.fingerprint", "Huawei/t1_10/hwt1a21l:5.1.1/HuaweiMediaPad/T1A23LC233B117:user/release-keys");
    }

    /* T1-A21W */
    else if (buf.find("T1-A21W") != std::string::npos) {
        property_override("ro.product.model", "T1-A21W");
        property_override("ro.product.device", "T1-A21W");
        property_override("ro.build.product", "T1-A21W");
        property_set("ro.telephony.default_network", "9");
        property_override("ro.build.description", "t1_10-user 5.1.1 HuaweiMediaPad C233B117 release-keys");
        property_override("ro.build.fingerprint", "Huawei/t1_10/hwt1a21l:5.1.1/HuaweiMediaPad/T1A23LC233B117:user/release-keys");
    }

    /* T1-A22L */
    else if (buf.find("T1-A22L") != std::string::npos) {
        property_override("ro.product.model", "T1-A22L");
        property_override("ro.product.device", "T1-A22L");
        property_override("ro.build.product", "T1-A22L");
        property_set("ro.telephony.default_network", "9");
        property_override("ro.build.description", "t1_10-user 5.1.1 HuaweiMediaPad C233B117 release-keys");
        property_override("ro.build.fingerprint", "Huawei/t1_10/hwt1a21l:5.1.1/HuaweiMediaPad/T1A23LC233B117:user/release-keys");
    }

    /* T1-A23L */
    else if (buf.find("T1-A23L") != std::string::npos) {
        property_override("ro.product.model", "T1-A23L");
        property_override("ro.product.device", "T1-A23L");
        property_override("ro.build.product", "T1-A23L");
        property_set("ro.telephony.default_network", "9");
        property_override("ro.build.description", "t1_10-user 5.1.1 HuaweiMediaPad C233B117 release-keys");
        property_override("ro.build.fingerprint", "Huawei/t1_10/hwt1a21l:5.1.1/HuaweiMediaPad/T1A23LC233B117:user/release-keys");
    }    
}
