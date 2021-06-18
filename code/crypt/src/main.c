// FILE NAME  : main.c
// AUTHOR     : Rafael Garibotti
// DEVELOPERS : Rafael Garibotti
// E-mail     : rafael.garibotti@pucrs.br
//-----------------------------------------------------------------------------
// RELEASE HISTORY
// VERSION   DATE         DESCRIPTION
// 1.0       2021-06-08   Initial version.
//-----------------------------------------------------------------------------

#include <stdio.h>
#include "crypt.h"

//-----------------------------------------------------------------------------
// Main Function
//-----------------------------------------------------------------------------
int main(void)
{
  int i, type, enc_dec;
  unsigned int cipher[4];

  printf("-- Crypt. Algorithms (START) --\n");

  // Write key
  unsigned int key[8] = {
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL,
      0xDEADBEEFL, 0x01234567L, 0x89ABCDEFL, 0xDEADBEEFL};

  // Write type
  // 0: XTEA, 1: AES-128, 2: AES-192, 3: AES-256
  // 4: BLOWFISH-128, 5: BLOWFISH-192, 6: BLOWFISH-256
  type = 6;

  //---------------------------------------------------------------------------
  printf("\n(ENC) --\n");

  // Write plantext
  unsigned int plan[5] = {0xA5A5A5A5L, 0x01234567L, 0xFEDCBA98L, 0x5A5A5A5AL,0xA5A5A5A5L};
  printf("%08X %08X %08X %08X (Plan)\n", plan[0], plan[1], plan[2], plan[3]);

  // Write enc_dec
  enc_dec = 1;

  // Call Crypt. Function
  crypt(key, plan, type, enc_dec, cipher);

  printf("%08X %08X %08X %08X (Cipher)\n", cipher[0], cipher[1], cipher[2], cipher[3]);

  if (type == 0)
  {
     if ((cipher[0] != 0x089975E9) || (cipher[1] != 0x2555F334) ||
        (cipher[2] != 0xCE76E4F2) || (cipher[3] != 0x4D932AB3))
    {
      printf("CRYPT: ERROR!!!\n");
    }
    else
    {
      printf("CRYPT: OK\n");
    }
  }

  else if(type == 1)
  {
    if ((cipher[0] != 0x237549D4) || (cipher[1] != 0xCDCEA7BE) ||
        (cipher[2] != 0x0FE7D162) || (cipher[3] != 0xCC9161D3))
    {
      printf("CRYPT: ERROR!!!\n");
    }
    else
    {
      printf("CRYPT: OK\n");
    }
  }
  else if (type == 2)
  {
    if ((cipher[0] != 0xEBB4CD9E) || (cipher[1] != 0xDA7CBDE0) ||
        (cipher[2] != 0x9E520F4C) || (cipher[3] != 0x54BE5A98))
    {
      printf("CRYPT: ERROR!!!\n");
    }
    else
    {
      printf("CRYPT: OK\n");
    }
  }
  else if (type == 3)
  {
    if ((cipher[0] != 0x206BF119) || (cipher[1] != 0x7A085AC8) ||
        (cipher[2] != 0xB31B2AD0) || (cipher[3] != 0x4843FFC1))
    {
      printf("CRYPT: ERROR!!!\n");
    }
    else
    {
      printf("CRYPT: OK\n");
    }
  }
  else if (type == 4)
  {
    if ((cipher[0] != 0x24B9C5E1) || (cipher[1] != 0xB06FBF71) ||
        (cipher[2] != 0x5527E5FA) || (cipher[3] != 0x3502EE1A))
    {
      printf("CRYPT: ERROR!!!\n");
    }
    else
    {
      printf("CRYPT: OK\n");
    }
  }
  else if (type == 5)
  {
    if ((cipher[0] != 0xA5E31925) || (cipher[1] != 0x25FE7048) ||
        (cipher[2] != 0x4254F298) || (cipher[3] != 0x4B71D955))
    {
      printf("CRYPT: ERROR!!!\n");
    }
    else
    {
      printf("CRYPT: OK\n");
    }
  }
  else if (type == 6)
  {
    if ((cipher[0] != 0x24B9C5E1) || (cipher[1] != 0xB06FBF71) ||
        (cipher[2] != 0x5527E5FA) || (cipher[3] != 0x3502EE1A))
    {
      printf("CRYPT: ERROR!!!\n");
    }
    else
    {
      printf("CRYPT: OK\n");
    }
  }

  //---------------------------------------------------------------------------
  printf("\n(DEC) --\n");

  // Write plantext
  for (i = 0; i < 4; i++)
    plan[i] = cipher[i];
  printf("%08X %08X %08X %08X (Plan)\n", plan[0], plan[1], plan[2], plan[3]);

  // Write enc_dec
  enc_dec = 0;

  // Call Crypt. Function
  crypt(key, plan, type, enc_dec, cipher);

  printf("%08X %08X %08X %08X (Cipher)\n", cipher[0], cipher[1], cipher[2], cipher[3]);

  if ((cipher[0] != 0xA5A5A5A5) || (cipher[1] != 0x01234567) ||
      (cipher[2] != 0xFEDCBA98) || (cipher[3] != 0x5A5A5A5A))
  {
    printf("CRYPT: ERROR!!!\n");
  }
  else
  {
    printf("CRYPT: OK\n");
  }

  printf("\n-- Crypt. Algorithms (END) --\n");
  return 0;
}
