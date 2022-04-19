#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>



int main()
{

  /**
   * @brief  bias = 2^14 - 1
   * 
   * 
   * 
   */

  /**
   * @brief 最小的正非规格化数
   * 
   * 
   * 
   * 非规格化的数范围在 0-1 之间（不考虑符号位），阶码位全为 0
   * E = - 2^14
   * 
   * V = 2^(-63) * 2^(E)
   * 
   * 0  -- 15个0 -- 62个0 -- 1
   */


  /**
   * @brief 最小的正规格化数
   * M = 1
   * E = U - bias ，最小为 1 - bias
   * 
   * V = 2^(1-bias)
   * 
   * 0 -- 14个0 -- 1 -- 63个0
   */

  /**
   * @brief 最大的规格化数
   * 
   *  E = bias
   *  M = 1 + (1 - 2^(-63))
   * 
   *  2^bias * (2-2^-63)
   * 
   *  0 -- 14个1 -- 0 -- 63个1
   * 
   */


  return 0;
}