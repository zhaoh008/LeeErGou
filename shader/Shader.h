#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glad/glad.h>
#include <spdlog/spdlog.h>

class Shader {
public:
    unsigned int ID;

    Shader(const char* vertexPath, const char* fragmentPath) ;

    // 析构函数
    ~Shader() {
        glDeleteProgram(ID);
    }

    // 禁止拷贝构造和拷贝赋值
    Shader(const Shader&) = delete;
    Shader& operator=(const Shader&) = delete;

    // 移动构造函数
    Shader(Shader&& other) noexcept : ID(0) {
        // 接管资源并将原始对象的资源ID置零
        ID = other.ID;
        other.ID = 0;
    }

    // 移动赋值运算符
    Shader& operator=(Shader&& other) noexcept {
        if (this != &other) {
            // 清理现有资源
            glDeleteProgram(ID);

            // 接管资源并将原始对象的资源ID置零
            ID = other.ID;
            other.ID = 0;
        }
        return *this;
    }
    // Activate the shader
    void use() ;

    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;

    // Utility function for checking shader compilation/linking errors.
    void checkCompileErrors(GLuint shader, const std::string& type) ;
private:
    bool is_file_exist(const std::string& name) {
        std::ifstream file(name.c_str());
        return file.good();
    }

};
