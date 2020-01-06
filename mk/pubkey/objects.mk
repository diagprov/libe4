
OBJS = \
       $(OBJDIR)/e4util.$O                \
       $(OBJDIR)/crypto/aes_siv.$O        \
       $(OBJDIR)/crypto/aes256enc_ref.$O  \
       $(OBJDIR)/crypto/sha3.$O           \
       $(OBJDIR)/crypto/keccakf1600.$O    \
       $(OBJDIR)/crypto/test_aes_siv.$O   \
       $(OBJDIR)/crypto/test_sha3.$O      \
       $(OBJDIR)/strlcpy.$O               \
       $(OBJDIR)/crypto/curve25519/curve25519-donna.$O \
       $(OBJDIR)/crypto/ed25519/add_scalar.$O \
       $(OBJDIR)/crypto/ed25519/fe.$O \
       $(OBJDIR)/crypto/ed25519/ge.$O \
       $(OBJDIR)/crypto/ed25519/keypair.$O \
       $(OBJDIR)/crypto/ed25519/sc.$O \
       $(OBJDIR)/crypto/ed25519/seed.$O \
       $(OBJDIR)/crypto/ed25519/sign.$O \
       $(OBJDIR)/crypto/ed25519/verify.$O \
       $(OBJDIR)/crypto/sha512.$O \
       $(OBJDIR)/crypto/xed25519.$O \
       $(OBJDIR)/e4pkcclient.$O

ifeq ("$(STORE)", "file")
OBJS := $(OBJS) $(OBJDIR)/e4c_pk_store_file.$O 
endif

ifeq ("$(STORE)", "mem")
OBJS := $(OBJS) $(OBJDIR)/e4c_pk_store_mem.$O
endif

