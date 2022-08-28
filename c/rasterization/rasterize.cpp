#include<fstream>
#include<cmath>

class Vertice
{
public:
    float x, y;
    Vertice(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    void fit(int width, int height)
    {
        x = (x * (width / 2)) + (width / 2);
        y = (-y * (height / 2)) + (height / 2);
    }
};

class Image
{
public:
    int width, height;
    unsigned char* pixels;

    Image(int width, int height)
    {
        this->width = width;
        this->height = height;
        pixels = new unsigned char[width * height * 3];
    }
    ~Image()
    {
        delete[] pixels;
    }

    void setPixel(int x, int y, int red, int green, int blue)
    {
        int help_var = ((y * width) + x) * 3;
        pixels[help_var + 0] = (char)red;
        pixels[help_var + 1] = (char)green;
        pixels[help_var + 2] = (char)blue;
    }
    void fillPixels(int red, int green, int blue)
    {
        int help_var = width * height * 3;
        for (int i = 0; i < help_var; i += 3) {
            pixels[i + 0] = (char)red;
            pixels[i + 1] = (char)green;
            pixels[i + 2] = (char)blue;
        }
    }

    // BARYCENTRIC TRIANGLE RASTERISATION
    float edgeFunction(const Vertice& A, const Vertice& B, const Vertice& P)
    {
        return ((P.x - A.x)*(B.y - A.y) - (P.y - A.y)*(B.x - A.x));
    }   

    void fillTriangleBarycentric(const Vertice& v0, const Vertice& v1, const Vertice& v2)
    {
        Vertice p(0.0f, 0.0f);
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                p.x = x + 0.5f; p.y = y + 0.5f;
                float w0 = edgeFunction(v1, v2, p);
                float w1 = edgeFunction(v2, v0, p);
                float w2 = edgeFunction(v0, v1, p);
                if (w0 >= 0 && w1 >= 0 && w2 >= 0) {
                    setPixel(x, y, 0, 0, 255);
                }
            }
        }
    }
};

int main()
{
    Image image(800, 600);
    image.fillPixels(255, 255, 255);

    Vertice a(0.0f, 0.0f);
    Vertice b(-1.0f, 0.0f);
    Vertice c(0.0f, -1.0f);

    a.fit(image.width, image.height);
    b.fit(image.width, image.height);
    c.fit(image.width, image.height);

    image.fillTriangleBarycentric(a, b, c);

    std::ofstream imageFile;
    imageFile.open("./drawing_triangle_test_image.ppm");
    imageFile << "P6\n" << image.width << " " << image.height << "\n255\n";
    imageFile.write((char*)image.pixels, image.width * image.height * 2);
    imageFile.close();

    return 0;
}