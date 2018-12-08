BUILD_DIR ?= /tmp/build

test: build
	${BUILD_DIR}/test
build:
	cmake --build ${BUILD_DIR}
conf:
	rm -rfv ${BUILD_DIR}
	mkdir -pv ${BUILD_DIR}
	root="$$(pwd)" && cd ${BUILD_DIR} && cmake "$$root"
	ln -svf ${BUILD_DIR}/compile_commands.json .
doc:
	${MAKE} -C doc html

.PHONY: \
	conf \
	doc \

