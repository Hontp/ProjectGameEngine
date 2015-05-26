#include "Terrain.h"

/** @brief: Initialise the terrain object.
    
    @param: verts (GLfloat[]) - Array of color values to be passed to the program's active vertex shader.
    @param: vertBufferSize (GLint) - Size of the verts array.
    @param: colors (GLfloat[]) - Array of color values to be passed to the program's active fragment shader.
    @param: colorBufferSize (GLint) - Size of teh colors array.

    Description: Pass the data into the Terrain object's internal Model object and run its initialisation.

    @pre: NONE.

    @post: Terrain is now fully functional.
*/
void Terrain::Init(GLfloat verts[], GLint vertBuffSize, GLfloat colors[], GLint colorBufferSize, GLfloat UVdata[], GLint uvBufferSize, const std::string &fileName){
	isTextured = true;

	// Generate a VAO object.
	gl::GenVertexArrays(1, &vertexArrayID);
	gl::BindVertexArray(vertexArrayID);

	////////////////////   BEGIN LOAD VERTEX DATA    ////////////////////////////

	for (unsigned short i = 0; i < vertBuffSize; i += 3){
		modelData.push_back(verts[i]);
		modelData.push_back(verts[i + 1]);
		modelData.push_back(verts[i + 2]);
	}

	for (unsigned short i = 0; i < colorBufferSize; i += 3){
		colorData.push_back(colors[i]);
		colorData.push_back(colors[i + 1]);
		colorData.push_back(colors[i + 2]);
	}

	for (unsigned short i = 0; i < uvBufferSize; i += 2){
		uvData.push_back(UVdata[i]);
		uvData.push_back(UVdata[i + 1]);
	}


	vBufferLength = vertBuffSize;

	// Generate a VBO object.
	gl::GenBuffers(1, &vertexBufferID);
	gl::GenBuffers(1, &colorBufferID);
	gl::GenBuffers(1, &uvBufferID);

	gl::BindBuffer(gl::ARRAY_BUFFER, vertexBufferID);
	gl::BufferData(gl::ARRAY_BUFFER, modelData.size(), &modelData[0], gl::STATIC_DRAW);
	modelData.clear();

	gl::BindBuffer(gl::ARRAY_BUFFER, colorBufferID);
	gl::BufferData(gl::ARRAY_BUFFER, colorData.size(), &colorData[0], gl::STATIC_DRAW);
	colorData.clear();

	gl::BindBuffer(gl::ARRAY_BUFFER, uvBufferID);
	gl::BufferData(gl::ARRAY_BUFFER, uvData.size(), &uvData[0], gl::STATIC_DRAW);
	uvData.clear();

	// First attribute buffer : vertices
	gl::EnableVertexAttribArray(VERTEX);
	gl::BindBuffer(gl::ARRAY_BUFFER, vertexBufferID);
	gl::VertexAttribPointer(
		VERTEX,						// attribute 0.
		3,							// size
		gl::FLOAT,					// type: GLfloat
		gl::FALSE_,					// normalized?
		(sizeof(float) * 3),		// stride
		(void*)0					// array buffer offset
		);

	////////////////////   END LOAD VERTEX DATA      ////////////////////////////


	////////////////////   BEGIN LOAD COLOR DATA     ////////////////////////////
	gl::EnableVertexAttribArray(COLOR);
	gl::BindBuffer(gl::ARRAY_BUFFER, colorBufferID);
	gl::VertexAttribPointer(
		VERTEX,						// attribute 0.
		3,							// size
		gl::FLOAT,					// type: GLfloat
		gl::FALSE_,					// normalized?
		(sizeof(float) * 3),		// stride
		(void*)0					// array buffer offset
		);

	////////////////////   END LOAD COLOR DATA       ////////////////////////////


	////////////////////   BEGIN LOAD TEXTURE DATA   ////////////////////////////

	gl::EnableVertexAttribArray(UV);
	gl::BindBuffer(gl::ARRAY_BUFFER, uvBufferID);
	gl::VertexAttribPointer(
		UV,							// attribute 2.
		2,                          // size
		gl::FLOAT,                  // type: GLfloat
		gl::FALSE_,                 // normalized?
		(sizeof(float) * 2),        // stride
		(void*)(0)					// array buffer offset
		);

	// Generate a texture (CURRENTLY NON-FUNCTIONAL).
	//texture.load(textureFile);

	////////////////////   END LOAD TEXTURE DATA     ////////////////////////////
}

/** @brief: Render the Terrain object onscreen.
    
    Description: Call the internal Model object's Render function.

    @pre: The Terrain object should be initialised.

    @post: The terrain has been drawn onscreen.
*/
void Terrain::Render(){
	// Draw the model array.
	gl::DrawArrays(gl::TRIANGLES, 0, vBufferLength);

	gl::DisableVertexAttribArray(VERTEX);
	gl::DisableVertexAttribArray(COLOR);
	gl::DisableVertexAttribArray(UV);
}

/** @brief: Clear data from the Terrain object.
    
    Description: Call the internal Model object's Destroy function.

    @pre: The Terrain object should be initialised.

    @post: The Terrain object's internal Model object is now empty.
*/
void Terrain::Destroy(){
	gl::DeleteBuffers(1, &vertexBufferID);
	gl::DeleteVertexArrays(1, &vertexArrayID);
}

/** @brief: Set factory to create non-textured terrain.

    @param: fileName (std::string) - Filepath used to reference a heightmap (.raw format).
    @param: size (GLuint) - Dimensions of the height map file.

    Description: This function initiliases the TerrainFactory to create terrain WITHOUT textures.
    
    @pre: fileName should point to a valid .raw file, and size should be the same as the dimensions of the file.

    @post: TerrainFactory is now fully functional.
*/
void TerrainFactory::Init(std::string fileName, GLuint size, std::string texFile){

	textureFilePath = texFile;

    ResetContainers();

    buildSize = size;

    // Buffer size = x dimension * z dimension * 6 vertices per quad * 3 values per vertice.
    dataBufferSize = size * size * 6 * 3;

    heightMapData = FileReader::ReadRAWFile(fileName);

    vertData = new float[dataBufferSize];

    colorData = new float[dataBufferSize];
}

/** @brief: Set the TerrainFactory's scaling.

    @param: sX (GLfloat) - Scale of geometry along the X-axis.
    @param: sY (GLfloat) - Scale of geometry along the Y-axis.
    @param: sZ (GLfloat) - Scale of geometry along the Z-axis.

    Description: Set the scaling for the geometry generated by the TerrainFactory object.

    @pre: NONE.

    @post: The TerrainFactory's scaling for all geometry has now been altered.
*/
void TerrainFactory::SetScaleFactor(GLfloat sX, GLfloat sY, GLfloat sZ){
    buildScale.x = sX;
    buildScale.y = sY;
    buildScale.z = sZ;
}

/** @brief: Build a terrain object using the TerrainFactory's loaded data.

    @param: _pos (glm::vec3) - co-ordinates to draw the new terrain object.

    Description: Build the terrain's VBO. Construct any required UV or color data. Output the new object.

    @return: Address to a new Terrain object at the _pos co-ordinates.
    
    @pre: Enough memory to create a new Terrain object with the data generated by the TerrainFactory.

    @post: A new Terrain object has been created.
*/
Terrain* TerrainFactory::BuildAt(glm::vec3 _pos){

    Terrain* terrain = new Terrain(buildSize);

    buildPosition = _pos;

    GLdouble xOffset = 0, zOffset = 0;
    int index = 0, uvIndex = 0;

    for(unsigned int x = 0; x < buildSize - 1; x++){
        for(unsigned int z = 0; z < buildSize - 1; z++){

            // Build in Quads. 6 vertices * 3 values each = 18 values per quad so...

            if(vertData == nullptr){
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

            if(!isTextured){
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

    // Move the vertex and color data to the Terrain object.
    terrain->Init(vertData, (GLint)(dataBufferSize), colorData, (GLint)(dataBufferSize), uvMapData, (GLint)(buildSize * buildSize * 2), textureFilePath);

    // return the terrain object.
    return terrain;

}

/** @brief: Get the current terrain's height at the specified point.
    
    Description: Get the height of the terrain that is currently being generated by the TerrainFactory, at the specifed co-ordinates.

    @return: The height value of the terrain at the specified point.

    @pre: Co-ordinates must point to a valid index.

    @post: NONE.
*/
GLfloat TerrainFactory::GetHeight(int x, int z){
    // heightMapData[(x * 128 + z)] approximates reading the array as heightMapData[x][z];
    // (x * 128 + z) * 3   because every value in heightMapData is written 3 times, so we only want to read each value ONCE out of those three times.
    return (GLfloat)((unsigned char)heightMapData[(x * buildSize + z) * 3]);
}

/** @brief: Fault algorithm for generating a heightMap.

    @param: outPutFile (std::string) - FilePath for the outputted .raw file.
    @param: dimensions (unsigned int) - Dimensions of the outputFile hieghtmap.
    @param: minHeight (float) - Minimum value that a pixel will be altered by.
    @param: maxHeight (float) - Maximum value that a pixel can be altered by.
    @param: iterations (unsigned int) - Number of faultlines that will be applied to the file.
    @param: weight (float) - Magnitude of effect applied by the fault lines.
    @param: random (boolean) - Toggle whether the algorithm is truly random, or just pseudo-random.

    Description: Generate a height map dynamically using the fault algorithm.

    @return: NO in-code return values, but a .raw file is created.
    
    @pre: There must be room in memory to store a .raw file of the dimensions specified.

    @post: A .raw file has been generated based on the parameters entered into the function.
*/
void TerrainFactory::generateRAW_faultLine(std::string outputFile, unsigned int dimensions, float minHeight, float maxHeight, unsigned int iterations, float weight, bool random){
    
    // Create a new 2D array.
    heightMap = new float[dimensions * dimensions];

    for(unsigned int i = 0; i < dimensions * dimensions; i++)
        heightMap[i] = 0.0f;
    
    unsigned int x1 = 0, x2 = 0, z1 = 0, z2 = 0, iterate = 0;

    float displacement = 0;

    if (random) //create truly random map
		srand ( time(NULL) );

    // Create the faultline alterations.
    do{
        x1 = (rand() % dimensions);
        z1 = (rand() % dimensions);

        iterate++;
        displacement = maxHeight - ((maxHeight - minHeight) * iterate) / iterations;

        do{
            x2 = (rand() % dimensions);
            z2 = (rand() % dimensions);
        }while(x2 == x1 && z2 == z1);

        for(unsigned int z = 0; z < dimensions; z++){
            for(unsigned int x = 0; x < dimensions; x++){
                int y = (x2 - x1) * (z - z1) - (z2 - z1) * (x - x1);
                if(y > 0){
                    heightMap[z * dimensions + x] += displacement;
                }
            }
        }

        Apply_FIR_Filter(heightMap, 0.5, dimensions);

    }while(iterate < iterations);

    Apply_Normalise(heightMap, dimensions);

    // Output the data to a .raw file.
    std::ofstream ofile_RAW2(outputFile.c_str());
    for(unsigned int x = 0; x < dimensions; x++){
        for(unsigned int y = 0; y < dimensions; y++){
            ofile_RAW2 << unsigned char((unsigned short)heightMap[x * dimensions + y]) << unsigned char((unsigned short)heightMap[x * dimensions + y]) << unsigned char((unsigned short)heightMap[x * dimensions + y]);
        }
    }
    ofile_RAW2.close();  // Close the output file.
};

/** @brief: Apply a single erosion pass to a height map.
    
    Description: Apply the FIR erosion algorithm to a height map in a single direction.

    @pre: data must point to a vaild float array. 'size' must match the dimensions of the height map.

    @post: data ahs been eroded in a single direction.
*/
void TerrainFactory::Apply_FIR_Pass(float* data, int increment, float weight, int size){

    float yPrev = data[0];
    int j = increment;
    float k = weight;

    for(int i = 1; i < size; i++){
        data[j] = (k * yPrev + (1 - k) * data[j]);
        yPrev = data[j];
        j += increment;
    }

}

/** @brief: Apply FIR algorithm in all directions.
    
    Description: Apply the FIR erosion algorithm to a valid height map in all four directions.

    @pre: data must point to a valid float array. 'size' must match the dimensions of the height map.

    @post: height map erosion has been completed.
*/
void TerrainFactory::Apply_FIR_Filter(float* data, float weight, int size){

    int i;

    for(i = 0; i < size; i++)
        Apply_FIR_Pass(&data[size * i], 1, weight, size);

    for(i = 0; i < size; i++)
        Apply_FIR_Pass(&data[size * i + size - 1], -1, weight, size);

    for(i = 0; i < size; i++)
        Apply_FIR_Pass(&data[i], size, weight, size);

    for(i = 0; i < size; i++)
        Apply_FIR_Pass(&data[size * (size - 1) + i], -size, weight, size);
}

/** @brief: Normalise a height map's values.
    
    Description: Normalise the height values of a heightmap.

    @pre: data must point to a valid float array. 'size' must match the dimensions of teh height map.

    @post: Heightmap has now been normalised.
*/
void TerrainFactory::Apply_Normalise(float* data, int size){

    float min, max, height;
    int i;
    min = data[0];
    max = data[0];

    for(i = 1; i < size * size; i++){

        if(data[i] > max)
            max = data[i];
        else
            if(data[i] < min)
                min = data[i];
    }

    if(max <= min)
        return;

    height = max - min;

    for(i = 0; i < size * size; i++){
        data[i] = (((data[i] - min) / height ) * 255.0f);
    }

}

/** @brief: Reset the data in the TerrainFactory object.
    
    Description: Clear each pointer that contains data. Reset them to nullptrs.

    @pre: NONE.

    @post: All data containers are now empty and reset to null pointers.
*/
void TerrainFactory::ResetContainers(){

    // Clear and reset the vertex data buffer.
    if(vertData != nullptr){
        delete[] vertData;
        vertData = nullptr;
    }

    // Clear and reset the color data buffer.
    if(colorData != nullptr){
        delete[] colorData;
        colorData = nullptr;
    }

    if(uvMapData != nullptr){
        delete[] uvMapData;
        uvMapData = nullptr;
    }

    if(heightMap != nullptr){
        delete[] heightMap;
        heightMap = nullptr;
    }

    // Clear and reset the height map data container.
    if(heightMapData != nullptr){
        delete[] heightMapData;
        heightMapData = nullptr;
    }

}