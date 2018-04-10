#
# Copyright (C) 2017 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# inherit from common smdk3470
-include device/samsung/smdk3470-common/BoardConfigCommon.mk

DEVICE_PATH := device/samsung/degaslte

# Assert
TARGET_OTA_ASSERT_DEVICE := degasltexx,degasltezt,degaslte

# Filesystems
# Note: the BOARD_...IMAGE_PARTITION_SIZE values define the image sizes, 
# not the partition sizes. So the image sizes can also be lower than the partition size. 

# Real partition sizes
#BOARD_BOOTIMAGE_PARTITION_SIZE := 10485760
#BOARD_CACHEIMAGE_PARTITION_SIZE := 209715200
#BOARD_RECOVERYIMAGE_PARTITION_SIZE := 12582912
#BOARD_SYSTEMIMAGE_PARTITION_SIZE := 2233466880
#BOARD_USERDATAIMAGE_PARTITION_SIZE := 5044699136????(-16384)

# Image sizes
BOARD_BOOTIMAGE_PARTITION_SIZE := 10485760
BOARD_CACHEIMAGE_PARTITION_SIZE := 209715200
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 12582912
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 2147483648
BOARD_USERDATAIMAGE_PARTITION_SIZE := 2147483648

# Include path
TARGET_SPECIFIC_HEADER_PATH += $(DEVICE_PATH)/include

# Kernel
TARGET_KERNEL_CONFIG := degaslte_00_defconfig
TARGET_KERNEL_SOURCE := kernel/samsung/degaslte

# GUI (Avoid Crash after entering sleep)
BOARD_EGL_NEEDS_HANDLE_VALUE := true

# CMHW
BOARD_HARDWARE_CLASS := device/samsung/degaslte/lineagehw

# Bluetooth
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR := $(DEVICE_PATH)/bluetooth

# NFC
# Chipset: Samsung s3fwrn5
# Note: as libnfc-nci only supports pn547 and bcm2079x, select pn547 here but use the stock s3fwrn5 hal
BOARD_NFC_CHIPSET := pn547
BOARD_NFC_HAL_SUFFIX := universal3470

# Recovery
TARGET_RECOVERY_DEVICE_DIRS += $(DEVICE_PATH)
TARGET_RECOVERY_FSTAB := $(DEVICE_PATH)/rootdir/etc/fstab.universal3470
BOARD_HAS_LARGE_FILESYSTEM := true

# PowerHAL
TARGET_POWERHAL_VARIANT := exynos3

# Lights
TARGET_PROVIDES_LIBLIGHT := true

# Vendor Init
TARGET_UNIFIED_DEVICE := true
TARGET_INIT_VENDOR_LIB := libinit_degaslte
TARGET_LIBINIT_DEFINES_FILE := $(DEVICE_PATH)/init/init_degaslte.cpp

# Don't take forever to wipe
BOARD_SUPPRESS_SECURE_ERASE := true
COMMON_GLOBAL_CFLAGS += -DNO_SECURE_DISCARD

# TWRP
DEVICE_RESOLUTION := 800x1280
RECOVERY_SDCARD_ON_DATA := true
BOARD_HAS_NO_REAL_SDCARD := true
TW_NO_REBOOT_BOOTLOADER := true
TW_HAS_DOWNLOAD_MODE := true
TWRP_INCLUDE_LOGCAT := true
TW_NO_LEGACY_PROPS := true

# SELinux
BOARD_SEPOLICY_DIRS := \
	$(DEVICE_PATH)/sepolicy
