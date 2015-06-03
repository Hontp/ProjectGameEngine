#include "TerrainFactory.h"

void TerrainFactory::Init(std::string fileName, GLuint size, std::string texFile){

	if (texFile != "")
		textureFilePath = texFile;
	else
		isTextured = false;

	ResetContainers();

	buildSize = size;

	// Buffer size = x dimension * z dimension * 6 vertices per quad * 3 values per vertice.
	dataBufferSize = size * size * 6 * 3;

	heightMapData = FileReader::ReadRAWFile(fileName);

	vertData = new float[dataBufferSize];

	colorData = new float[dataBufferSize];
}

void TerrainFactory::SetScaleFactor(GLfloat sX, GLfloat sY, GLfloat sZ){
	buildScale.x = sX;
	buildScale.y = sY;
	buildScale.z = sZ;
}

Terrain* TerrainFactory::BuildAt(glm::vec3 _pos){

	Terrain* terrain = new Terrain(buildSize);

	buildPosition = _pos;

	GLdouble xOffset = 0, zOffset = 0;
	int index = 0, uvIndex = 0;

	for (unsigned int x = 0; x < buildSize - 1; x++){
		for (unsigned int z = 0; z < buildSize - 1; z++){

			// Build in Quads. 6 vertices * 3 values each = 18 values per quad so...

			if (vertData == nullptr){
				std::cout << "PING";
				return nullptr;
			}

			////////////////////////// BEGIN TRIANGLE 1 VERTEX SETTING. ////////////////////////////
			// Point 1.
			vertData[index + 0] = float(buildPosition.x + (xOffset));
			vertData[index + 1] = float(buildPosition.y + (GetHeight(x, z) * buildScale.y));
			vertData[index + 2] = float(buildPosition.z + (zOffset));

			// Point 2.
			vertData[index + 3] = float(buildPosition.x + xOffset + (1.0f * buildScale.x));
			vertData[index + 4] = float(buildPosition.y + (GetHeight(x, z + 1) * buildScale.y));
			vertData[index + 5] = float(buildPosition.z + (zOffset));

			// Point 3.
			vertData[index + 6] = float(buildPosition.x + (xOffset));
			vertData[index + 7] = float(buildPosition.y + (GetHeight(x + 1, z) * buildScale.y));
			vertData[index + 8] = float(buildPosition.z + zOffset + (1.0f * buildScale.z));
			////////////////////////// END TRIANGLE 1 VERTEX SETTING.   ////////////////////////////

			////////////////////////// BEGIN TRIANGLE 2 VERTEX SETTING. ////////////////////////////
			// Point 1 ( of 4).
			vertData[index + 9] = float(buildPosition.x + (xOffset));
			vertData[index + 10] = float(buildPosition.y + (GetHeight(x + 1, z) * buildScale.y));
			vertData[index + 11] = float(buildPosition.z + zOffset + (1.0f * buildScale.z));

			// Point 2 ( of 5).
			vertData[index + 12] = float(buildPosition.x + xOffset + (1.0f * buildScale.x));
			vertData[index + 13] = float(buildPosition.y + (GetHeight(x, z + 1) * buildScale.y));
			vertData[index + 14] = float(buildPosition.z + (zOffset));

			// Point 3 ( of 6).
			vertData[index + 15] = float(buildPosition.x + xOffset + (1.0f * buildScale.x));
			vertData[index + 16] = float(buildPosition.y + (GetHeight(x + 1, z + 1) * buildScale.y));
			vertData[index + 17] = float(buildPosition.z + zOffset + (1.0f * buildScale.z));
			////////////////////////// END TRIANGLE 2 VERTEX SETTING.   ////////////////////////////

			if (!isTextured){
				////////////////////////// BEGIN TRIANGLE 1 COLOR SETTING.  ////////////////////////////

				colorData[index + 0] = float(GetHeight(x, z) / 255.0f);
				colorData[index + 1] = float(GetHeight(x, z) / 255.0f);
				colorData[index + 2] = float(GetHeight(x, z) / 255.0f);

				colorData[index + 3] = float(GetHeight(x, z + 1) / 255.0f);
				colorData[index + 4] = float(GetHeight(x, z + 1) / 255.0f);
				colorData[index + 5] = float(GetHeight(x, z + 1) / 255.0f);

				colorData[index + 6] = float(GetHeight(x + 1, z) / 255.0f);
				colorData[index + 7] = float(GetHeight(x + 1, z) / 255.0f);
				colorData[index + 8] = float(GetHeight(x + 1, z) / 255.0f);

				////////////////////////// END TRIANGLE 1 COLOR SETTING.    ////////////////////////////

				////////////////////////// BEGIN TRIANGLE 2 COLOR SETTING.  ////////////////////////////

				colorData[index + 9] = float(GetHeight(x + 1, z) / 255.0f);
				colorData[index + 10] = float(GetHeight(x + 1, z) / 255.0f);
				colorData[index + 11] = float(GetHeight(x + 1, z) / 255.0f);

				colorData[index + 12] = float(GetHeight(x, z + 1) / 255.0f);
				colorData[index + 13] = float(GetHeight(x, z + 1) / 255.0f);
				colorData[index + 14] = float(GetHeight(x, z + 1) / 255.0f);

				colorData[index + 15] = float(GetHeight(x + 1, z + 1) / 255.0f);
				colorData[index + 16] = float(GetHeight(x, z + 1) / 255.0f);
				colorData[index + 17] = float(GetHeight(x, z + 1) / 255.0f);

				////////////////////////// END TRIANGLE 2 COLOR SETTING.    ////////////////////////////
			}
			else{
				////////////////////////// BEGIN TRIANGLE 1 UV SETTING.  ////////////////////////////
				uvMapData[uvIndex] = 0.0f;
				uvMapData[uvIndex + 1] = 0.0f;

				uvMapData[uvIndex + 2] = 1.0f;
				uvMapData[uvIndex + 3] = 0.0f;

				uvMapData[uvIndex + 4] = 0.0f;
				uvMapData[uvIndex + 5] = 1.0f;
				////////////////////////// END TRIANGLE 1 UV SETTING.    ////////////////////////////

				////////////////////////// BEGIN TRIANGLE 2 UV SETTING.  ////////////////////////////
				uvMapData[uvIndex + 6] = 0.0f;
				uvMapData[uvIndex + 7] = 1.0f;

				uvMapData[uvIndex + 8] = 1.0f;
				uvMapData[uvIndex + 9] = 0.0f;

				uvMapData[uvIndex + 10] = 1.0f;
				uvMapData[uvIndex + 11] = 1.0f;
				////////////////////////// END TRIANGLE 2 UV SETTING.    ////////////////////////////

				uvIndex += 12;
			}


			xOffset += 1.0f * buildScale.x; // Shuffle the offset across the x-axis by one scaled unit every quad.

			index += 18;
		}

		xOffset = 0.0f;
		zOffset = (x + 1) * (1.0f * buildScale.z);     // Shuffle the offset across the z-axis by one scaled unit every quad ROW.
	}

	if (isTextured)
		terrain->Init(vertData, (GLint)(dataBufferSize), colorData, (GLint)(dataBufferSize), uvMapData, (GLint)(buildSize * buildSize * 2), textureFilePath);
	else
		terrain->Init(vertData, (GLint)(dataBufferSize), colorData, (GLint)(dataBufferSize), nullptr, 0, "");

	// return the terrain object.
	return terrain;

}

GLfloat TerrainFactory::GetHeight(int x, int z){
	// heightMapData[(x * 128 + z)] approximates reading the array as heightMapData[x][z];
	// (x * 128 + z) * 3   because every value in heightMapData is written 3 times, so we only want to read each value ONCE out of those three times.
	return (GLfloat)((unsigned char)heightMapData[(x * buildSize + z) * 3]);
}

void TerrainFactory::generateRAW_faultLine(std::string outputFile, unsigned int dimensions, float minHeight, float maxHeight, unsigned int iterations, float weight, bool random){

	// Create a new 2D array.
	heightMap = new float[dimensions * dimensions];

	for (unsigned int i = 0; i < dimensions * dimensions; i++)
		heightMap[i] = 0.0f;

	unsigned int x1 = 0, x2 = 0, z1 = 0, z2 = 0, iterate = 0;

	float displacement = 0;

	if (random) //create truly random map
		srand(time(NULL));

	// Create the faultline alterations.
	do{
		x1 = (rand() % dimensions);
		z1 = (rand() % dimensions);

		iterate++;
		displacement = maxHeight - ((maxHeight - minHeight) * iterate) / iterations;

		do{
			x2 = (rand() % dimensions);
			z2 = (rand() % dimensions);
		} while (x2 == x1 && z2 == z1);

		for (unsigned int z = 0; z < dimensions; z++){
			for (unsigned int x = 0; x < dimensions; x++){
				int y = (x2 - x1) * (z - z1) - (z2 - z1) * (x - x1);
				if (y > 0){
					heightMap[z * dimensions + x] += displacement;
				}
			}
		}

		Apply_FIR_Filter(heightMap, 0.5, dimensions);

	} while (iterate < iterations);

	Apply_Normalise(heightMap, dimensions);

	// Output the data to a .raw file.
	std::ofstream ofile_RAW2(outputFile.c_str());
	for (unsigned int x = 0; x < dimensions; x++){
		for (unsigned int y = 0; y < dimensions; y++){
			ofile_RAW2 << unsigned char((unsigned short)heightMap[x * dimensions + y]) << unsigned char((unsigned short)heightMap[x * dimensions + y]) << unsigned char((unsigned short)heightMap[x * dimensions + y]);
		}
	}
	ofile_RAW2.close();  // Close the output file.
};

void TerrainFactory::Apply_FIR_Pass(float* data, int increment, float weight, int size){

	float yPrev = data[0];
	int j = increment;
	float k = weight;

	for (int i = 1; i < size; i++){
		data[j] = (k * yPrev + (1 - k) * data[j]);
		yPrev = data[j];
		j += increment;
	}

}

void TerrainFactory::Apply_FIR_Filter(float* data, float weight, int size){

	int i;

	for (i = 0; i < size; i++)
		Apply_FIR_Pass(&data[size * i], 1, weight, size);

	for (i = 0; i < size; i++)
		Apply_FIR_Pass(&data[size * i + size - 1], -1, weight, size);

	for (i = 0; i < size; i++)
		Apply_FIR_Pass(&data[i], size, weight, size);

	for (i = 0; i < size; i++)
		Apply_FIR_Pass(&data[size * (size - 1) + i], -size, weight, size);
}

void TerrainFactory::Apply_Normalise(float* data, int size){

	float min, max, height;
	int i;
	min = data[0];
	max = data[0];

	for (i = 1; i < size * size; i++){

		if (data[i] > max)
			max = data[i];
		else
			if (data[i] < min)
				min = data[i];
	}

	if (max <= min)
		return;

	height = max - min;

	for (i = 0; i < size * size; i++){
		data[i] = (((data[i] - min) / height) * 255.0f);
	}

}

void TerrainFactory::ResetContainers(){

	// Clear and reset the vertex data buffer.
	if (vertData != nullptr){
		delete[] vertData;
		vertData = nullptr;
	}

	// Clear and reset the color data buffer.
	if (colorData != nullptr){
		delete[] colorData;
		colorData = nullptr;
	}

	if (uvMapData != nullptr){
		delete[] uvMapData;
		uvMapData = nullptr;
	}

	if (heightMap != nullptr){
		delete[] heightMap;
		heightMap = nullptr;
	}

	// Clear and reset the height map data container.
	if (heightMapData != nullptr){
		delete[] heightMapData;
		heightMapData = nullptr;
	}
}
