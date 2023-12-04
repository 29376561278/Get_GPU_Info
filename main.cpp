﻿#include <Windows.h>
#include <iomanip>
#include <stdio.h>

#include <stdlib.h>

#include "./config/gpuMonitor.h"

#pragma comment(lib, "cfgmgr32.lib")

static char* TAG = "main.cpp:\t";

int main(int argc, char *argv[])
{
    //if (argc < 2)
    //{
    //    LOGE << TAG << "Invalid input command arguments.\n";
    //    return -1;
    //}

    //DWORD pid = std::stoul(argv[1]);
    DWORD pid = 14288;

    LOGI << TAG << "Monitor " << pid << "\n";

    if (!loadDll())
    {
        LOGE << TAG << "loadDll Error.\n";
        return 1;
    }

    if (!loadFunc())
    {
        LOGE << TAG << "loadFunc Error.\n";
        return 1;
    }

    //ULONG WindowsVersion = 0;
    //WindowsVersion = getWindowsVersion();
    //printf("Vesion: %ul.\n", WindowsVersion);

    GpuMonitor monitor(pid);
    if (!monitor.start())
    {
        LOGE << TAG << "monitor.start failed.\n";
        return -1;
    }

    LOGI << TAG << "start collect.\n";
  /*  while (true)
    {*/
        LOGI << "\n\n";
        std::vector<FLOAT_ULONG64> dataList = monitor.collect();

        //LOGI << TAG << "GPU_TARGET_PROCESS_UTILIZATION: " << dataList[GPU_TARGET_PROCESS_UTILIZATION].float_ << "\n";
        //LOGI << TAG << "GPU_TARGET_PROCESS_DEDICATED_USAGE: " << dataList[GPU_TARGET_PROCESS_DEDICATED_USAGE].ulong64_ << "\n";
        //LOGI << TAG << "GPU_DEDICATED_LIMIT: " << dataList[GPU_DEDICATED_LIMIT].ulong64_ << "\n";
        //LOGI << TAG << "GPU_TARGET_PROCESS_SHARED_USAGE: " << dataList[GPU_TARGET_PROCESS_SHARED_USAGE].ulong64_ << "\n";
        //LOGI << TAG << "GPU_SHARED_LIMIT: " << dataList[GPU_SHARED_LIMIT].ulong64_ << "\n";

        LOGI << "\n===============================================================\n";
        LOGI << TAG << "GPU 专用资源限制:                " << dataList[GPU_DEDICATED_LIMIT].ulong64_ / 1024 / 1024 << "MB \n";
        
        LOGI << TAG << "GPU 系统专用资源使用率:         " << dataList[GPU_SYSTEM_DEDICATED_USAGE].ulong64_ / 1024 / 1024 << "MB \n";
                LOGI << TAG << "GPU 系统共享资源使用率:            " << dataList[GPU_SYSTEM_SHARED_USAGE].ulong64_ / 1024 / 1024 << "MB \n";

        LOGI << "===============================================================\n";
    //}
    


    LOGI << TAG << "process exit sucessfully.\n";
    return 0;
}