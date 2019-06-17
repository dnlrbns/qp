IDIR =../include
CC = clang
CFLAGS = -I$(IDIR)

ODIR = obj
LDIR =../lib

LIBS = -lm

_DEPS = qp.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = qp.o func.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

qp.app: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ *.app
