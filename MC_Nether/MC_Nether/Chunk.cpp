#include "Chunk.h"

int Chunk::GenerateBlockType(glm::vec3 pos)
{

    float genHeight = GenHeight(pos);

    if (pos.y > genHeight)
    {
        return NONE;
    }
    else if (pos.y <= genHeight && pos.y > genHeight - 5)
    {
        int random = rand() % 50;
        if (random < 5) {
            return SOUL_SAND;
        }
        else if (random == 49) {
            return SAND;
        }
        else if (random <= 49 && random > 36) {
            return NONE;
        }
        else {
            return NETHER_RACK;
        }    
    }
    else
    {
        int random = rand() % 70;
        if (random < 5) {
            return DIAMOND_ORE;
        }
        else if (random > 60) {
            return GOLD_ORE;
        }
        else if (random <= 60 && random > 50) {
            return NONE;
        }
        else {
            return NETHER_RACK;
        }
        
    }
}

int Chunk::GenHeight(glm::vec3 pos)
{
    float x0 = (pos.x + offset0.x) * frequency;
    float y0 = (pos.y + offset0.y) * frequency;
    float z0 = (pos.z + offset0.z) * frequency;

    float x1 = (pos.x + offset1.x) * frequency * 2;
    float y1 = (pos.y + offset1.y) * frequency * 2;
    float z1 = (pos.z + offset1.z) * frequency * 2;

    float x2 = (pos.x + offset2.x) * frequency / 4;
    float y2 = (pos.y + offset2.y) * frequency / 4;
    float z2 = (pos.z + offset2.z) * frequency / 4;

    SimplexNoise sNoise;
    float noise0 = (sNoise.noise(x0, y0, z0) + 1) * amplitude;
    float noise1 = (sNoise.noise(x1, y1, z1) + 1) * amplitude / 2;
    float noise2 = (sNoise.noise(x1, y1, z1) + 1) * amplitude / 4;

    return floor(noise0 + noise1 + noise2 + baseHeight);
}

void Chunk::setTransPos(glm::vec3 tran)
{
    float half = blockWid / 2;
    transPos = tran;
    boun.minx = tran.x - half;
    boun.maxx = tran.x + (blockWid * width) + half;
    boun.miny = tran.y - half;
    boun.maxy = tran.y + (blockWid * height) + half;
    boun.minz = tran.z - half;
    boun.maxz = tran.z + (blockWid * width) + half;
}

glm::vec3 Chunk::getTransPos()
{
    return transPos;
}

Chunk::Chunk()
{
    Cubic cube;
    blockWid = cube.getCubeWidth();
    initMap();
}

Chunk::Chunk(glm::vec3 trans)
{
    Cubic cube;
    blockWid = cube.getCubeWidth();

    setTransPos(trans);
	initMap();
}

void Chunk::initMap()
{
	srand(time(0));
	offset0 = glm::vec3(rand(), rand(), rand());
	offset1 = glm::vec3(rand(), rand(), rand());
	offset2 = glm::vec3(rand(), rand(), rand());

    float half = blockWid / 2;

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            for (int z = 0; z < width; z++)
            {
                map[x][y][z] = GenerateBlockType(glm::vec3(x, y, z));
                float opx = x * blockWid;
                float opy = y * blockWid;
                float opz = z * blockWid;
                opx += transPos.x;
                opy += transPos.y;
                opz += transPos.z;

                worldCoor[x][y][z] = glm::vec3(opx, opy, opz);

                cubeBouns[x][y][z] = boundary(opx - half, opx + half, opy - half,
                    opy + half, opz - half, opz + half);
            }
        }
    }
}
