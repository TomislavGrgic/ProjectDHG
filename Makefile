CC = arm-none-eabi-gcc
CDEBUG = arm-none-eabi-gdb

MCU_FLAGS = -D TM4C123GH6PM -D PART_TM4C123GH6PM -D TARGET_IS_TM4C123_RB1

LDFLAGS = -T Core/TivaC/tm4c123g.ld

BUILD_PATH = ./.build
OBJS_PATH = $(BUILD_PATH)/objs

SOURCE_FILES = 	main.c\
				startup_gcc.c\
				tm4c_gpio.c\
				gpio.c\
				gpio_port.c\
				tm4c_qei.c\
				tm4c_pwm.c\
				pwm.c\
				pwm_port.c\
				encoder.c\
				encoder_port.c\
				tm4c_systick.c
				
OBJECT_FILES = $(SOURCE_FILES:.c=.o)
OBJECT_FILES_PTH = $(addprefix $(OBJS_PATH)/, $(SOURCE_FILES:.c=.o))

vpath %.c Core/TivaC/src
vpath %.c Drivers/src/gpio
vpath %.c Drivers/src/pwm
vpath %.c Drivers/src/encoder
vpath %.o $(OBJS_PATH)

HEDAER_FILES = -ICore/CMSIS/inc\
			-ICore/TivaC/inc\
			-IDrivers/inc\
			-IDrivers/inc/gpio\
			-IDrivers/inc/pwm\
			-IDrivers/inc/encoder\

PROCESSOR_FLAGS = -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mthumb

BUILD_FLAGS = $(PROCESSOR_FLAGS) -std=c11 -O0 -g $(HEDAER_FILES) $(MCU_FLAGS) -nostartfiles -nostdlib

OUTPUT_NAME = firmware.elf

FALSHER = ./OpenOCD/openocd.exe
FALSHER_FLAGS = -f ./OpenOCD/ti-icdi.cfg -c "transport select hla_jtag" -c "adapter speed 1000" -f ./OpenOCD/stellaris.cfg
FLASHER_PROGRAM = -c "program $(BUILD_PATH)/$(OUTPUT_NAME) verify reset exit"


all: clean create_dir build flash

debug: clean create_dir build
	$(FALSHER) $(FALSHER_FLAGS)

create_dir:
	mkdir -p $(BUILD_PATH)
	mkdir -p $(OBJS_PATH)


build: $(OUTPUT_NAME)


%.o: %.c
	$(CC) $(BUILD_FLAGS) -c $< -o $(OBJS_PATH)/$@


$(OUTPUT_NAME): $(OBJECT_FILES)
	$(CC) $(BUILD_FLAGS) $(LDFLAGS) $(OBJECT_FILES_PTH) -o $(BUILD_PATH)/$@


clean:
	rm -f $(OBJS_PATH)/*.o $(BUILD_PATH)/*.elf


flash: 
	$(FALSHER) $(FALSHER_FLAGS) $(FLASHER_PROGRAM) 
