namespace HEMacroForms
{
    internal static class Program
    {
        /// <summary>
        ///  The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            var task = Task.Factory.StartNew(
                () => HEMacro.runMacro()
            );

            ApplicationConfiguration.Initialize();
            Application.Run(new Form1());

            HEMacro.stopMacro();
            //task.Wait();
        }
    }
}