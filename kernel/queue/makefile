INC_PATH:=./include/
SRC_PATH:=./src/
OBJ_PATH:=./obj/

CC:=gcc

INC:=$(wildcard ${INC_PATH}*.h)
SRC:=$(wildcard ${SRC_PATH}*.c)
OBJ:=$(patsubst ${SRC_PATH}%.c, ${OBJ_PATH}%.o, ${SRC})

TARGET_OBJ:=output.o
TARGET:=output

define create_obj_folder
	if [ ! -d ${OBJ_PATH} ]; then mkdir -p ${OBJ_PATH}; fi
endef

all:${TARGET}
	@echo ${OBJ}

${TARGET}:${OBJ}
	${CC} ${OBJ} -o ${TARGET}

${OBJ}:${OBJ_PATH}%.o:${SRC_PATH}%.c
	@$(call create_obj_folder)
	${CC} -c $< -o $@ -I ${INC_PATH}

clean:
	rm -f ${OBJ} ${TARGET}

.PHONY:
	clean
