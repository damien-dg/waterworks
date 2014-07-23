#include "Loader.h"

std::vector<glm::vec3> Loader::loadOBJ(Renderer renderer, char* path){

	std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
	std::vector< glm::vec3 > temp_vertices;
	std::vector< glm::vec2 > temp_uvs;
	std::vector< glm::vec3 > temp_normals;
	std::vector< glm::vec3 > out_vertices;
	FILE * file = fopen(path, "r");
	if (file == NULL){

		printf("Impossible to open the file !\n");
		//return false;
	}
	else{
		

		while (1){
			
			char lineHeader[128];
			int res = fscanf(file, "%s", lineHeader);
		
			if (res == EOF) break;
			
			//handle all "v" entries in object file (regular vertices)
			if (strcmp(lineHeader, "v") == 0){
				glm::vec3 vertex;
				fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
				temp_vertices.push_back(vertex);
			}
			//handle "vt" entries, texture coords
			else if (strcmp(lineHeader, "vt") == 0){
				glm::vec2 uv;
				fscanf(file, "%f %f\n", &uv.x, &uv.y);
				temp_uvs.push_back(uv);
			}
			//handle all "vn" entries, normals
			else if (strcmp(lineHeader, "vn") == 0){
				glm::vec3 normal;
				fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
				temp_normals.push_back(normal);
			}
			//handle all "f" entries, face coords
			else if (strcmp(lineHeader, "f") == 0){
				std::string vertex1, vertex2, vertex3;
				unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
				int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
				if (matches != 9){
					printf("File can't be read by our simple parser : ( Try exporting with other options\n");
					//return false;
				}
				vertexIndices.push_back(vertexIndex[0]);
				vertexIndices.push_back(vertexIndex[1]);
				vertexIndices.push_back(vertexIndex[2]);
				uvIndices.push_back(uvIndex[0]);
				uvIndices.push_back(uvIndex[1]);
				uvIndices.push_back(uvIndex[2]);
				normalIndices.push_back(normalIndex[0]);
				normalIndices.push_back(normalIndex[1]);
				normalIndices.push_back(normalIndex[2]);
			}

			
			
		}
		for (int i = 0; i < vertexIndices.size(); i++){
			unsigned int vertexIndex = vertexIndices[i];
			glm::vec3 vertex = temp_vertices[vertexIndex - 1];
			out_vertices.push_back(vertex);
		}
		std::vector<glm::vec3> vertices;
		
		for (int i = 0; i < vertices.size(); i++){
			printf("%f, %f, %f\n", vertices.at(i).x, vertices.at(i).y, vertices.at(i).z);
		}
	
		return out_vertices;
		
	}


}