#ifndef OBC_SOFTWARE_LITTLEFS_HPP
#define OBC_SOFTWARE_LITTLEFS_HPP

#include "lfs.h"
#include "NANDFlash.h"

class LittleFS {
public:

    lfs_t littlefs;

    static uint8_t LUN;

    const struct lfs_config cfg = {
            // block device operations
            .read  = [](const struct lfs_config *c, lfs_block_t block,
                        lfs_off_t off, void *buffer, lfs_size_t size) {
                MT29F::Structure *pos{};
                pos->block = block;
                pos->page = off;
                pos->LUN = LUN;
                MT29F nand(SMC::NCS3, MEM_NAND_BUSY_1_PIN, MEM_NAND_WR_ENABLE_PIN);

                int ret = nand.abstractReadNAND(pos, MT29F::PAGE_BLOCK,
                                                etl::span<uint8_t>(static_cast<uint8_t *>(buffer), size), size);
                return ret;
            },
            .prog  = [](const struct lfs_config *c, lfs_block_t block,
                        lfs_off_t off, const void *buffer, lfs_size_t size) {
                MT29F::Structure *pos{};
                pos->block = block;
                pos->page = off;
                pos->LUN = LUN;
                MT29F nand(SMC::NCS3, MEM_NAND_BUSY_1_PIN, MEM_NAND_WR_ENABLE_PIN);

                int ret = nand.abstractWriteNAND(pos, MT29F::PAGE_BLOCK,
                                                 etl::span<const uint8_t>(static_cast<const uint8_t *>(buffer), size),
                                                 size);
                return ret;
            },
            .erase = [](const struct lfs_config *c, lfs_block_t block) {
                MT29F nand(SMC::NCS3, MEM_NAND_BUSY_1_PIN, MEM_NAND_WR_ENABLE_PIN);

                int ret = nand.eraseBlock(LUN, block);
                return ret;
            },
//            .sync  = ,
            // block device configuration
            .read_size = 16, // TODO: Revisit those minimum size parameters when the data to be stored are evaluated
            .prog_size = 16,
            .block_size = 1080,
            .block_count = 4096,
            .block_cycles = 1000,
            .cache_size = 16,
            .lookahead_size = 512
    };

    LittleFS(uint8_t LUN) {
        this->LUN = LUN;
    }

};


#endif //OBC_SOFTWARE_LITTLEFS_HPP
