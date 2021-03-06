
OBJS = $(OBJDIR)/e4util.$O                \
       $(OBJDIR)/crypto/aes_siv.$O        \
       $(OBJDIR)/crypto/aes256enc_ref.$O  \
       $(OBJDIR)/crypto/sha3.$O           \
       $(OBJDIR)/crypto/keccakf1600.$O    \
       $(OBJDIR)/crypto/test_aes_siv.$O   \
       $(OBJDIR)/crypto/test_sha3.$O      \
       $(OBJDIR)/strlcpy.$O               \
       $(OBJDIR)/e4symclient.$O 

ifeq ("$(STORE)", "file")
OBJS := $(OBJS) $(OBJDIR)/e4c_store_file.$O 
endif

ifeq ("$(STORE)", "mem")
OBJS := $(OBJS) $(OBJDIR)/e4c_store_mem.$O
endif
