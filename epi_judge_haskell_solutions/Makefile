HC = ghc 
OPTFLAG = -O2
BUILD_DIR = build
BUILD_CMD = ${HC} ${OPTFLAG} -outputdir ${BUILD_DIR} 

RECTANGLE_INTERSECTION = rectangleIntersection
COUNT_BITS = countBits
PARITY = parity
SWAP_BITS = swapBits

.PHONY: ${RECTANGLE_INTERSECTION}
${BUILD_DIR}/${RECTANGLE_INTERSECTION}: ${BUILD_DIR} ${RECTANGLE_INTERSECTION}.hs
	@echo "Compiling ${RECTANGLE_INTERSECTION}.hs"
	${BUILD_CMD} -o ${BUILD_DIR}/${RECTANGLE_INTERSECTION} ${RECTANGLE_INTERSECTION}.hs
${RECTANGLE_INTERSECTION}: ${BUILD_DIR}/${RECTANGLE_INTERSECTION}
	@echo "Running ${RECTANGLE_INTERSECTION}"
	${BUILD_DIR}/${RECTANGLE_INTERSECTION}
	@rm -f ${BUILD_DIR}/Main.hi ${BUILD_DIR}/Main.o

.PHONY: ${COUNT_BITS}
${BUILD_DIR}/${COUNT_BITS}: ${BUILD_DIR} ${COUNT_BITS}.hs
	@echo "Compiling ${COUNT_BITS}.hs"
	${BUILD_CMD} -o ${BUILD_DIR}/${COUNT_BITS} ${COUNT_BITS}.hs
${COUNT_BITS}: ${BUILD_DIR}/${COUNT_BITS}
	@echo "Running ${COUNT_BITS}"
	${BUILD_DIR}/${COUNT_BITS}
	@rm -f ${BUILD_DIR}/Main.hi ${BUILD_DIR}/Main.o	

.PHONY: ${PARITY}
${BUILD_DIR}/${PARITY}: ${BUILD_DIR} ${PARITY}.hs
	@echo "Compiling ${PARITY}.hs"
	${BUILD_CMD} -o ${BUILD_DIR}/${PARITY} ${PARITY}.hs
${PARITY}: ${BUILD_DIR}/${PARITY}
	@echo "Running ${PARITY}"
	${BUILD_DIR}/${PARITY}
	@rm -f ${BUILD_DIR}/Main.hi ${BUILD_DIR}/Main.o

.PHONY: ${SWAP_BITS}
${BUILD_DIR}/${SWAP_BITS}: ${BUILD_DIR} ${SWAP_BITS}.hs
	@echo "Compiling ${SWAP_BITS}.hs"
	${BUILD_CMD} -o ${BUILD_DIR}/${SWAP_BITS} ${SWAP_BITS}.hs
${SWAP_BITS}: ${BUILD_DIR}/${SWAP_BITS}
	@echo "Running ${SWAP_BITS}"
	${BUILD_DIR}/${SWAP_BITS}
	@rm -f ${BUILD_DIR}/Main.hi ${BUILD_DIR}/Main.o

${BUILD_DIR}: 
	@echo "Creating build directory"
	mkdir -p ${BUILD_DIR}

.PHONY: all
all: \
	${COUNT_BITS} \
	${PARITY} \
	${SWAP_BITS} \
	${RECTANGLE_INTERSECTION}

.PHONY: clean 
clean:
	@echo "Cleaning up..."
	rm -rf ${BUILD_DIR}/