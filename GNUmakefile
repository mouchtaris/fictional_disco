BUILD_DIR ?= /tmp/build

test: build
	${BUILD_DIR}/sms
build:
	cmake --build ${BUILD_DIR}
conf: clean
	mkdir -pv ${BUILD_DIR}
	root="$$(pwd)" && cd ${BUILD_DIR} && env CMAKE_GENERATOR=Ninja cmake "$$root"
	ln -svf ${BUILD_DIR}/compile_commands.json .
doc:
	${MAKE} -C doc html
clean:
	rm -rfv ${BUILD_DIR}

.PHONY: \
	clean \
	conf \
	doc \
	test \

