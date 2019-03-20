
#ifndef GRAIN128AEAD_32P_H
#define GRAIN128AEAD_32P_H

typedef uint8_t		u8;
typedef uint16_t	u16;
typedef uint32_t	u32;
typedef uint64_t	u64;


// 4 words key and IV, 12 init rounds, 1024 rounds before reinit = 1040
#define BUF_SIZE 1040

typedef struct {
	u32 lfsr[BUF_SIZE];
	u32 nfsr[BUF_SIZE];
	u32 *lptr;
	u32 *nptr;
	u32 count;
	u16 acc[4];
	u16 reg[BUF_SIZE];
} grain_ctx;

void grain_init(grain_ctx *, const u8 *, const u8 *);
void grain_reinit(grain_ctx *);
u32 next_keystream(grain_ctx *);


#endif
