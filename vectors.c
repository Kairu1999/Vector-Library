/*Author: Shane-Kyle Chua / Kairu1999*/
/*This is purely for interest to see how linear algebra's basics can tie in to coding*/

#include <stdio.h>

/*Struct for a 2D Vector*/
struct TwoDimVector {
    int num1;
    int num2;
};

/*Struct for a 3D vector*/
struct ThreeDimVector{
    int num1;
    int num2;
    int num3;
};

/*Struct for a 2D matrix)
struct TwoDimMatrix{
    struct TwoDimVector e1;
    struct TwoDimVector e2;
};

/*Struct for a 3D matrix*/
struct ThreeDimMatrix{
    struct ThreeDimVector e1;
    struct ThreeDimVector e2;
    struct ThreeDimVector e3;
};

//Two dimensional Matrix Addition
struct TwoDimMatrix matrixAdd(struct TwoDimMatrix m1, struct TwoDimMatrix m2){
    
    struct TwoDimMatrix NewMatrix;
    
    NewMatrix.e1.num1 =  m1.e1.num1 + m2.e1.num1;
    NewMatrix.e1.num2 =  m1.e1.num2 + m2.e1.num2;
    NewMatrix.e2.num1 =  m1.e2.num1 + m2.e2.num1;
    NewMatrix.e2.num2 =  m1.e2.num2 + m2.e2.num2;
    
    return NewMatrix;
}
/*Calculate the 2 dimensional dot product*/
int TwoDimDotProduct(struct TwoDimVector vector1, struct TwoDimVector vector2){
    int dotproduct = (vector1.num1 * vector2.num1) + (vector1.num2 * vector2.num2);
    return dotproduct;
}

/*Calculate the 3 dimensional dot product*/
int ThreeDimDotProduct(struct ThreeDimVector vector1, struct ThreeDimVector vector2){
    int dotproduct = (vector1.num1 * vector2.num1) + (vector1.num2 * vector2.num2) + (vector1.num3 * vector2.num3);
    return dotproduct;
}

/*Calculate 2D Projection(Non-Matrix)*/
struct TwoDimVector projection(struct TwoDimVector a1, struct TwoDimVector a2){
    //if a1 is u, a2 is v, proju(v) = (a2.a1 / a1.a1)a1
    
    //declare a new vector to store the projection
    struct TwoDimVector NewVector;
    
    //calculate the projection
    int dotproductone = TwoDimDotProduct(a1,a2);
    int dotproducttwo = TwoDimDotProduct(a1,a1);
    int projection = (dotproductone / dotproducttwo);
    
    NewVector.num1 = a1.num1 * projection;
    NewVector.num2 = a1.num2 * projection;
    
    return NewVector;
}

/*Calculate the 3D cross product*/
struct ThreeDimVector crossProduct(struct ThreeDimVector vector1, struct ThreeDimVector vector2){
    struct ThreeDimVector vector3;
    int newval1 = (vector1.num2 * vector2.num3) - (vector1.num3 * vector2.num2);
    int newval2 = (vector1.num3 * vector2.num1) - (vector1.num1 * vector2.num3);
    int newval3 = (vector1.num1 * vector2.num2) - (vector1.num2 * vector2.num1);
    
    vector3.num1 = newval1;
    vector3.num2 = newval2;
    vector3.num3 = newval3;
    
    return vector3;
}

/*Purpose of main is to test stuff*/
int main()
{
    
    int x1 = 1, y1 = 2, x2 = 3,y2 = 4, z1 = 5, z2 = 6;
    // struct TwoDimVector v1, v2;
    // struct ThreeDimVector v3,v4;
    struct TwoDimMatrix m1, m2;
    m1.e1.num1 = x1;
    m1.e1.num2 = y1;
    m1.e2.num1 = x2;
    m1.e2.num2 = y2;
    
    //make both the same for ease
    m2.e1.num1 = x1;
    m2.e1.num2 = y1;
    m2.e2.num1 = x2;
    m2.e2.num2 = y2;
    v1.num1 = x1;
    v1.num2 = y1;
    v2.num1 = x2;
    v2.num2 = y2;
    v3.num1 = x1;
    v3.num2 = y1;
    v3.num3 = z1;
    v4.num1 = x2;
    v4.num2 = y2;
    v4.num3 = z2;
    int dotproduct = TwoDimDotProduct(v1,v2);
    int threedotproduct = ThreeDimDotProduct(v3,v4);
    struct ThreeDimVector threecrossproduct = crossProduct(v3,v4);
    struct TwoDimVector twoDProjection = projection(v1,v2);
    struct TwoDimMatrix addMatrix = matrixAdd(m1,m2);
    //printf("%d\n",dotproduct);
    //printf("%d\n",threedotproduct);
    //printf("%d %d %d",threecrossproduct.num1, threecrossproduct.num2, threecrossproduct.num3);
    // printf("Vector after projection is [%d %d]",twoDProjection.num1,twoDProjection.num2);
    printf("New Matrix after addition: [%d %d | %d %d]",addMatrix.e1.num1,addMatrix.e1.num2, 
            addMatrix.e2.num1, addMatrix.e2.num2);
            
    /*Exit*/
    return 0;
}



