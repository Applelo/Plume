/*
**
** Made by Applelo
**
*/

#ifndef CLOUD_HH_
# define CLOUD_HH_

# include "Utils.h"

class Cloud {
private:
	float _xCloud[10];
	float _yCloud[10];
	int _typeCloud[10];
	int _position;
	bool _statut;
	vita2d_texture* _texture;

public:
	Cloud();
	virtual ~Cloud();

	//Setter
	void setTexture(vita2d_texture* texture);
	void setStatut(const bool statut);

	//Getter
	const bool getStatut() const;

	// Display
	void displayCloud();


};

#endif /* !CLOUD_HH_ */
