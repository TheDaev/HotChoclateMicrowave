using System;
using System.Diagnostics;
using System.ComponentModel;

/*
 * microwave build to build a project.
 * microwave start {project_name} to make config file.
 */ 

namespace M.I.C.R.O.W.A.V.E
{
    internal class Program
    {
        static void Main(string[] args)
        {
            if (args[0] == "build")
            {
                if ((File.Exists("lib/Engine.lib")) && Directory.Exists("include"))
                {
                    string ProjectName = File.ReadAllLines("ProConf")[0];
                    Process.Start("dontremove");
                }
                else
                {
                    Console.WriteLine(".lib or include/ does not exist. ");
                }
            }
            else if (args[0] == "start")
            {
                if ((File.Exists("lib/Engine.lib")) && Directory.Exists("include"))
                {
                    string ProjectName = args[1];
                    File.WriteAllText("ProConf", ProjectName);
                    File.WriteAllText("dontremove", $"g++ main.cpp -I./include -L./lib -lEngine -o {ProjectName}");
                }
                else
                {
                    Console.WriteLine(".lib or include/ does not exist. ");
                }
            }
            else
            {
                Console.WriteLine("Not a command. ");
            }
        }
    }
}