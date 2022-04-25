Pipeline - класс конвейера.
С помощью функций Scale, WorldPos, Rotate можем установить значения в приватный одноименные переменные.
Функция Gettrans инициализирует матрицы для преобразований, передает их в следующие функции, возвращает матрицу преобразований.
initscaletransform, initrotatetransform, inittranslation преобразуют матрицы основываясь на приватных переменных класса.

void glUniformMatrix4fv(	GLint location,
 				GLsizei count,
 				GLboolean transpose,
 				const GLfloat *value); 
функция добавления unifotm переменной в шейдер
