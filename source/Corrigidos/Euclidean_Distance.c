/*Author: Gustavo Nogueira
 *Date: 28/12/2017
 */

/*This function is responsible for calculating the Euclidean distance between a normalized histogram(an image being tested) and other two vectors that characterize the two image classes.
 *Returns "g" if the image is classified as being of the Grass class. Returns "a" if the image is classified as being of class Asphalt.*/

char Euclidean_Distance(double **feature_Vectors, double *avg_Grass, double *avg_Asphalt,int index, int sizeVector){
    double grass_dist;
    double asphalt_dist;
    double sum_grass = 0;
    double sum_asphalt = 0;
    int i;

    for (i = 0;i < sizeVector;i++){
        sum_grass += pow((feature_Vectors[index][i] - *(avg_Grass+i)),2);
        sum_asphalt += pow((feature_Vectors[index][i] - *(avg_Asphalt+i)),2);
    }
    grass_dist = sqrt(sum_grass);
    asphalt_dist = sqrt(sum_asphalt);

    if (asphalt_dist > grass_dist){
        return 'g';
    }
    else {
        return 'a';
    }

}



