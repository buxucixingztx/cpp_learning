#include <iostream>
#include <cmath>
#include <fstream>


int main()
{
    int sampleRate = 50;
    int data[50][6];
    int gyro_xyz[3][50];
    std::ifstream fp;
    
    fp.open("E:\\test.txt", std::ios::in);

    if (!fp.is_open()){
        std::cout << "fail to open file!!\n";
        return 1;
    }

    // fp >> x_a >> y_a >> z_a >> x_g >> y_g >> z_g;
    for (int i = 0; i < sampleRate; i++){
        for (int j = 0; j < 6; j++)
    {
        fp >> data[j][i];
    };
    for (int j=0; j<3; j++)
    {
        gyro_xyz[j][i] = data[i][j+3];
    }
    }

    float average[3];
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < sampleRate; i++)
        {
            average[j] += 1.0f * gyro_xyz[j][i];
        }
    }

    for (int j = 0; j < 3; j++)
    {
        average[j] = average[j] / (float)sampleRate;
    };

    float sumSquare[3] = {0.0f}, cid_ce[3] = {0.0f}, variance[3], std_deviation[3], tempCG[3];
    for (int)
    
    for (int j = 0; j < 2; j++){
        for (int i = 0; i < 6; i++)
    {
        std::cout << data[j][i] << ' ';
    };
    std::cout << '\n';
    }
    std::cout << '\n';
    
    fp.close();

    return 0;
}