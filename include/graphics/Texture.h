#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <boost/filesystem.hpp>
#include "stb_image.h"

class Texture {
public:
    Texture(const std::string& path){

        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_2D, textureID);

        // Set the texture wrapping parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        // Set texture filtering parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


        int width, height, nrChannels;
        stbi_set_flip_vertically_on_load(true);
        unsigned char* data = stbi_load(boost::filesystem::absolute(path).string().c_str(), &width, &height, &nrChannels, 0);
        if (data) {
            GLenum format = GL_RGB;
            if (nrChannels == 4) {
                format = GL_RGBA;
            } else if (nrChannels == 1) {
                format = GL_RED;
            }
            glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        } else {
            std::cerr << "Failed to load texture at path: " << path << std::endl;
        }
        stbi_image_free(data);
    }

    Texture(const Texture&) = delete;


    Texture& operator=(const Texture&) = delete;


    Texture(Texture&& other) noexcept
            : textureID(0) {
        std::swap(textureID, other.textureID);
    }


    Texture& operator=(Texture&& other) noexcept {
        if (this != &other) {
            glDeleteTextures(1, &textureID);
            std::swap(textureID, other.textureID);
        }
        return *this;
    }

    ~Texture() {
        glDeleteTextures(1, &textureID);
    }


    void bind() const {
        glBindTexture(GL_TEXTURE_2D, textureID);
    }

    static void unbind() {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

   GLuint getTextureId() const {
        return textureID;
    }

private:
    GLuint textureID{};


};