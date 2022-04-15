static void RenderSceneCB() 
Это функция рендера. Очищает буфер кадра, создает матрицу преобразований, загружает данные в шейдер, рисует треугольник по кадрам.
static void InitializeGlutCallbacks() 
Добавляет функцию рендера, указываеn функцию рендера в качестве ленивой
static void CreateVertexBuffer()
Создаем вершины треугольника, добавляем в буфер
static void AddShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType)
Gluint ShaderProgaram - переменная для хранения указателя
const char* pShaderText - текст шейдера в виде массива char
GLenum ShaderType - тип шейдера
Функция для добавления шейдера из строк
