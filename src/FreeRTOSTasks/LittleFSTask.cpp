#include "LittleFSTask.hpp"

void LittleFSTask::execute() {

    LittleFS littleFs(0);

    lfs_file_t file;

    int err = lfs_mount(&littleFs.littlefs, &littleFs.cfg);

    // reformat if we can't mount the filesystem
    // this should only happen on the first boot
    if (err) {
        lfs_format(&littleFs.littlefs, &littleFs.cfg);
        lfs_mount(&littleFs.littlefs, &littleFs.cfg);
    }

    // read current count
    uint32_t boot_count = 0;
    lfs_file_open(&littleFs.littlefs, &file, "boot_count", LFS_O_RDWR | LFS_O_CREAT);
    lfs_file_read(&littleFs.littlefs, &file, &boot_count, sizeof(boot_count));

    // update boot count
    boot_count += 1;
    lfs_file_rewind(&littleFs.littlefs, &file);
    lfs_file_write(&littleFs.littlefs, &file, &boot_count, sizeof(boot_count));

    // remember the storage is not updated until the file is closed successfully
    lfs_file_close(&littleFs.littlefs, &file);

    // release any resources we were using
    lfs_unmount(&littleFs.littlefs);

    // print the boot count
    LOG_DEBUG << "boot_count: %d\n" << boot_count;


};