#include <fmt/core.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void init();
GLFWwindow* createWindow(int width, int height, const char* titleName);
void setContext(GLFWwindow* win);

void processInput(GLFWwindow* win);

void framebuffer_size_callback(GLFWwindow* win, int width, int height);

static constexpr int WIDTH  = 800;
static constexpr int HEIGHT = 600;

int main()
{
    init();
    auto win = createWindow(WIDTH, HEIGHT, "Learn OpenGL");
    setContext(win);

    while (!glfwWindowShouldClose(win))
    {
        processInput(win);

        glClearColor(40.f / 255, 44.f / 255, 52.f / 255, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(win);
        glfwPollEvents();
    }

    glfwTerminate();
}

void init()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

GLFWwindow* createWindow(int width, int height, const char* titleName)
{
    GLFWwindow* win = glfwCreateWindow(width, height, titleName, nullptr, nullptr);
    if (win == nullptr)
    {
        fmt::println("Failed to create window");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    return win;
}

void setContext(GLFWwindow* win)
{
    glfwMakeContextCurrent(win);
    glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);
    
    static bool first = true;
    if (first)
    {
        first = false;
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            fmt::println("Failed to initialize glad");
            exit(EXIT_FAILURE);
        }
    }
}

void framebuffer_size_callback(GLFWwindow* win, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* win)
{
    if (glfwGetKey(win, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(win, true);
    }
}