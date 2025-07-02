#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include "esp_err.h"
#include "esp_spiffs.h"
#include "esp_log.h"

void app_main(void)
{
        esp_vfs_spiffs_conf_t config = {
                .base_path = "/storage",
                .partition_label = NULL,
                .max_files = 5,
                .format_if_mount_failed = true
        };
        esp_err_t result = esp_vfs_spiffs_register(&config);
        if(result != ESP_OK){
                ESP_LOGE("FileSystem", "Failed to initialize SPIFFS (%s)", esp_err_to_name(result));
                return;
        }
        size_t total = 0, used = 0;
        result = esp_spiffs_info(config.partition_label, &total, &used);
        if(result != ESP_OK){
                ESP_LOGE("FileSystem", "Failed to get partition info (%s)", esp_err_to_name(result));
                return;
        }
        ESP_LOGI("FileSystem", "Partition Size: total: %d, used: %d", total, used);
        FILE* f = fopen("/storage/myfile.txt", "r");
        if(f == NULL){
                ESP_LOGE("FILE", "Error reading file from storage\n");
                return;
        }
        char line[1024] = {0};
        fgets(line, sizeof(line), f);
        fclose(f);
        printf("%s\n", line);
}
