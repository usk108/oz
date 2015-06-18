CPP	= gcc
CFLAGS	= -O3 -Wall
DEBUG	= -g
LIB	= -framework OpenGL -framework GLUT -framework OpenAL
CSRCS = 2_toba.c objects.c glm.c
COBJS = ${CSRCS:.c=.o}

ALL: oz
oz: ${COBJS}
	${CPP} ${CFLAGS} ${DEBUG} -o $@ ${COBJS} ${LIB} 
.c.o:
	${CPP} ${CFLAGS} ${DEBUG} -c $<
clean:
	rm -f *.o *.*~ *~ oz
