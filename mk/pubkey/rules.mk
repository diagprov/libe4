
pub_lib: setup pub_header $(OBJS)
	mkdir -p $(LIBDIR); \
        cp -rfv $(INCDIR)/* $(OUTINCDIR)/; \
	$(AR) $(ARFLAGS) $(LIB) $(OBJS)

pub_so: setup pub_header $(OBJS)
	mkdir -p $(LIBDIR); \
        cp -rfv $(INCDIR)/* $(OUTINCDIR)/; \
	$(CC) $(LDSOFLAGS) $(OBJS) -o $(LIBSO)

.PHONY pub_header: $(BUILDDIR)/include/e4config/e4_config.h

$(BUILDDIR)/include/e4config/e4_config.h:
	echo '#define E4_MODE_PUBKEY 1' > $@
ifeq ("$(STORE)", "mem")
	echo "#define E4_STORE_MEM 1" >> $@
endif
ifeq ("$(STORE)", "file")
	echo "#define E4_STORE_FILE 1" >> $@
endif


E4LIBS += pub_lib
