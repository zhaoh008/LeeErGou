#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "glad/glad.h"
#include "spdlog/spdlog.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

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

    void setVec2(const std::string &name, const glm::vec2 &value) const
    {
        glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
    }
    void setVec2(const std::string &name, float x, float y) const
    {
        glUniform2f(glGetUniformLocation(ID, name.c_str()), x, y);
    }
    // ------------------------------------------------------------------------
    void setVec3(const std::string &name, const glm::vec3 &value) const
    {
        glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
    }
    void setVec3(const std::string &name, float x, float y, float z) const
    {
        glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);
    }
    // ------------------------------------------------------------------------
    void setVec4(const std::string &name, const glm::vec4 &value) const
    {
        glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
    }
    void setVec4(const std::string &name, float x, float y, float z, float w)
    {
        glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w);
    }
    // ------------------------------------------------------------------------
    void setMat2(const std::string &name, const glm::mat2 &mat) const
    {
        glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
    // ------------------------------------------------------------------------
    void setMat3(const std::string &name, const glm::mat3 &mat) const
    {
        glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
    // ------------------------------------------------------------------------
    void setMat4(const std::string &name, const glm::mat4 &mat) const
    {
        glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }

    // Utility function for checking shader compilation/linking errors.
    void checkCompileErrors(GLuint shader, const std::string& type) ;
private:
    static bool is_file_exist(const std::string& name) {
        std::ifstream file(name.c_str());
        return file.good();
    }

};
