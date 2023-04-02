namespace Microwave
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string include_path = args[0]+"include";
            string lib_path = args[0]+"lib";
            string[] main_cpp = {
                "#include \"Window.h\"",
                "",
                "int main(){",
                "Window& gameWindow = new Window::get()",
                "gameWindow->run();",
                "return 0;",
                "}"};

            string[] compile_sh = {
                "",
                "",
                "",

                   };
            
            


        }
    }
}