/*Author: Shane-Kyle Chua / Kairu1999*/
/*This is purely for interest to see how linear algebra's basics can tie in to coding*/
#include <stdio.h>

struct TwoDimVector {
    int num1;
    int num2;
};

struct ThreeDimVector{
    int num1;
    int num2;
    int num3;
};

struct TwoDimMatrix{
    struct TwoDimVector e1;
    struct TwoDimVector e2;
};

struct ThreeDimMatrix{
    struct ThreeDimVector e1;
    struct ThreeDimVector e2;
    struct ThreeDimVector e3;
};

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
int main()
{
    int x1 = 1, y1 = 2, x2 = 3,y2 = 4, z1 = 5, z2 = 6;
    struct TwoDimVector v1, v2;
    struct ThreeDimVector v3,v4;
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
    //printf("%d\n",dotproduct);
    //printf("%d\n",threedotproduct);
    //printf("%d %d %d",threecrossproduct.num1, threecrossproduct.num2, threecrossproduct.num3);
    printf("Vector after projection is [%d %d]",twoDProjection.num1,twoDProjection.num2);
    return 0;
}

