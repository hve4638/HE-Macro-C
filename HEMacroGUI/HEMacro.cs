﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace HEMacroGUI
{
    public static class HEMacro
    {
        [DllImport("HEMacro.dll")]
        extern public static void runMacro();

        [DllImport("HEMacro.dll")]
        extern public static void stopMacro();

        [DllImport("HEMacro.dll")]
        extern public static void clearInputQueue();
        
        [DllImport("HEMacro.dll")]
        extern public static int writeQueueLog(string filename);
    }
}
