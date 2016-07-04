#ifndef radio_h
#define radio_h

#include "serial_api.h"
#include "motorcontroller.h"

const int RADIO_OUT_BUFFER_SIZE = 64;
#define RF_DEFAULT    0b00100011  // 250kbps 0dB
#define TRANSMIT_ADDRESS   "clie1"
#define RECEIVE_ADDRESS    "serv1"

enum {
    PACKET_PRINT_VERSION,
    PACKET_PRINT_ROLE,
    PACKET_PRINT_MAX_VELOCITY,
    PACKET_PRINT_ACCEL,
    PACKET_PRINT_Z_MAX_VELOCITY,
    PACKET_PRINT_Z_ACCEL,
    PACKET_PRINT_CHANNEL,
    PACKET_GET_VERSION,
    PACKET_GET_ROLE,
    PACKET_GET_MAX_VELOCITY,
    PACKET_GET_ACCEL,
    PACKET_GET_Z_MAX_VELOCITY,
    PACKET_GET_Z_ACCEL,
    PACKET_GET_CHANNEL,
    PACKET_SET_TARGET_POSITION,
    PACKET_SET_MAX_VELOCITY,
    PACKET_SET_ACCEL,
    PACKET_SET_Z_MAX_VELOCITY,
    PACKET_SET_Z_ACCEL,
    PACKET_SET_MODE,
    PACKET_SET_CHANNEL,
    PACKET_SET_VELOCITY_PERCENT,
    PACKET_SET_ACCEL_PERCENT,
};


struct typed_val_packet_t {
    char type;
    int val;
};

struct typed_uval_packet_t {
    char type;
    unsigned int val;
};

struct radio_packet_t {
    union {
        char type;
        typed_val_packet_t typed_val;
        typed_uval_packet_t typed_uval;
    };
};

struct serial_api_state_t;

struct radio_state_t {
    lh::MotorController* motor_controller;
    serial_api_state_t* serial_state;
    radio_packet_t buffer[RADIO_OUT_BUFFER_SIZE];
    int write_index;
    int read_index;
};

void radio_init(radio_state_t* state);
void radio_run(radio_state_t* state);
void radio_queue_message(radio_state_t* state, radio_packet_t packet);
void radio_set_channel(int channel);

#endif //radio_h