#pragma once

class Material{

	public:

		Material(){};	// Constructor.

		/**	@brief: Activate the current material.

			@param: NONE.

			Description: Activate the current material as the active material. Used when drawing to specify the correct material to draw on the model.

			@return: NONE.
		*/
		virtual void Activate() = 0;

		virtual void Deactivate() = 0;

};