INC_PATH:=./include/
SRC_PATH:=./src/
OBJ_PATH:=./obj/

CC:=g++

INC:=$(wildcard ${INC_PATH}*.h)
SRC:=$(wildcard ${SRC_PATH}*.cpp)
OBJ:=$(patsubst ${SRC_PATH}%.cpp, ${OBJ_PATH}%.o, ${SRC})

TARGET_OBJ:=output.o
TARGET:=output

define createfolder
	if [ ! -d ${OBJ_PATH} ]; then mkdir -p ${OBJ_PATH}; fi
endef

all:${TARGET}
	

${TARGET}:${OBJ}
	${CC} ${OBJ} -o ${TARGET}

${OBJ}:${OBJ_PATH}%.o:${SRC_PATH}%.cpp
	@$(call createfolder)
	${CC} -c $< -o $@ -I ${INC_PATH}

# ${OBJ_PATH}:
# 	$(call createfolder)

clean:
	rm -f ${OBJ} ${TARGET}
	rmdir ${OBJ_PATH}

.PHONY:
	clean
