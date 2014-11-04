#include "Texture.h"


void Texture::bind()
 { 
	 //glBindTexture(GL_TEXTURE_2D, 0);
	// if (id) 
	// { 
		 //glActiveTexture(GL_TEXTURE0); 
		glBindTexture(GL_TEXTURE_2D, id); 
	// }
}