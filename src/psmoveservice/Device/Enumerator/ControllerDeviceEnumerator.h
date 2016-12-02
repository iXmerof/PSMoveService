#ifndef CONTROLLER_DEVICE_ENUMERATOR_H
#define CONTROLLER_DEVICE_ENUMERATOR_H

#include "DeviceEnumerator.h"
#include "USBDeviceInfo.h"

class ControllerDeviceEnumerator : public DeviceEnumerator
{
public:
	enum eAPIType
	{
		CommunicationType_INVALID= -1,
		CommunicationType_HID,
		CommunicationType_LIBUSB,
		CommunicationType_ALL
	};

    ControllerDeviceEnumerator(eAPIType api_type);
    ControllerDeviceEnumerator(eAPIType api_type, CommonDeviceState::eDeviceType deviceType);
    ~ControllerDeviceEnumerator();

    bool is_valid() const override;
    bool next() override;
    const char *get_path() const override;

    bool get_serial_number(char *out_mb_serial, const size_t mb_buffer_size) const;
	t_usb_device_handle get_usb_device_handle() const;
	eAPIType get_api_type() const;

private:
	eAPIType api_type;
	DeviceEnumerator **enumerators;
	int enumerator_count;
	int enumerator_index;
};

#endif // CONTROLLER_DEVICE_ENUMERATOR_H