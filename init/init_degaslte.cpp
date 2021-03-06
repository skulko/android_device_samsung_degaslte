/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include <android-base/properties.h>

#include "vendor_init.h"
#include "property_service.h"

/* #include "log.h"
#include "util.h" */
#define LOG_TAG "init_properties"
#include <cutils/log.h>

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void vendor_load_properties()
{
   /* char platform[PROP_VALUE_MAX];
    char bootloader[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];
    int rc;

    rc = property_get("ro.board.platform", platform);
    if (!rc || strncmp(platform, ANDROID_TARGET, PROP_VALUE_MAX))
        return;

    property_get("ro.bootloader", bootloader); */
	
    std::string platform = android::base::GetProperty("ro.board.platform", "");
    std::string bootloader = android::base::GetProperty("ro.bootloader", "");

    if (platform != ANDROID_TARGET) {
        return;
    }


    if (bootloader.find("T235Y") != std::string::npos) {
        /* degasltezt */
	property_override("ro.build.fingerprint", "samsung/degasltezt/degaslte:4.4.2/KOT49H/T235YZTU1AOD1:user/release-keys");
	property_override("ro.build.description", "degasltezt-user 4.4.2 KOT49H T235YZTU1AOD1 release-keys");
        property_override("ro.product.model", "SM-T235Y");
        property_override("ro.product.device", "degasltezt");
    } else if (bootloader.find("T235") != std::string::npos) {
        /* degasltexx */
        property_override("ro.build.fingerprint", "samsung/degasltexx/degaslte:4.4.2/KOT49H/T235XXU1AOD1:user/release-keys");
        property_override("ro.build.description", "degasltexx-user 4.4.2 KOT49H T235XXU1AOD1 release-keys");
        property_override("ro.product.model", "SM-T235");
        property_override("ro.product.device", "degasltexx");
     }
    
    std::string device = android::base::GetProperty("ro.product.device", "");
    ALOGI("Found bootloader id %s setting build properties for %s device\n", bootloader.c_str(), device.c_str());
}
