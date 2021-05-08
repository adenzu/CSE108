#include <stdio.h>
#include <math.h>



/*===Part1===*/

typedef struct matrix_s{
    double values[3][3];
    double determinant;
} matrix;


void determinant_of_matrix(matrix *initial_matrix){
    initial_matrix->determinant = 0;

    int product;
    int i, j;
    int x, y;
    for(i = 0; i < 3; ++i){
        product = 1;

        for(j = 0; j < 3; ++j){
            y = j % 3;
            x = (i + j) % 3;
            product *= initial_matrix->values[y][x];
        }

        initial_matrix->determinant += product;
    }
    
    for(i = 0; i < 3; ++i){
        product = 1;

        for(j = 0; j < 3; ++j){
            y = j % 3;
            x = (i - j) < 0 ? i - j + 3 : i - j;
            product *= initial_matrix->values[y][x];
        }

        initial_matrix->determinant -= product;
    }
}

double determinant_submatrix(const matrix *initial_matrix, int x, int y){
    double determinant = 0;

    int i, j, k;
    for(i = 0; i < 3; ++i){
        for(j = 0; j < 3; ++j){
            if(i != y && j != x){
                if(i == j){
                    for(k = 1; k < 3; ++k){
                        if((i+k) != y && (j+k) != x){
                            determinant += initial_matrix->values[i][j] * initial_matrix->values[i+k][j+k];
                        }
                    }
                }
                else if(i != j){
                    for(k = 1; k < 3; ++k){
                        if((i-k) != y && (j-k) != x){
                            determinant -= initial_matrix->values[i][j] * initial_matrix->values[i+k][j+k];
                        }
                    }
                }
            }
        }
    }
    
    return determinant;
}

void scan_matrix(matrix *scanned_matrix){
    double new_value;
    int i, j;
    for(i = 0; i < 3; ++i){
        for(j = 0; j < 3; ++j){
            scanf("%lf", &new_value);
            scanned_matrix->values[i][j] = new_value;
        }
    }

    determinant_of_matrix(scanned_matrix);
}

void print_matrix(matrix initial_matrix){
    int i, j;
    for(i = 0; i < 3; ++i){
        for(j = 0; j < 3; ++j)
            printf("%.4lf ", initial_matrix.values[i][j]);
        printf("\n");
    }
}

void copy_matrix(const matrix *initial_matrix, matrix *copied_matrix){
    int i, j;
    for(i = 0; i < 3; ++i)
        for(j = 0; j < 3; ++j)
            copied_matrix->values[i][j] = initial_matrix->values[i][j];

    copied_matrix->determinant = initial_matrix->determinant;
}

void transpose_matrix(const matrix *initial_matrix, matrix *transposed_matrix){
    int i, j;
    for(i = 0; i < 3; ++i)
        for(j = 0; j < 3; ++j)
            transposed_matrix->values[i][j] = initial_matrix->values[j][i];

    transposed_matrix->determinant = initial_matrix->determinant;
}

void inverse_matrix(const matrix *initial_matrix, matrix *inverted_matrix){
    matrix adjugated;
    matrix adjugated_T;

    double abs_det = initial_matrix->determinant;
    abs_det *= abs_det < 0 ? -1 : 1;

    if(!abs_det){
        printf("Doesn't have inverse.\n");
        return;
    }

    int i, j;
    for(i = 0; i < 3; ++i){
        for(j = 0; j < 3; ++j){
            adjugated.values[i][j] = determinant_submatrix(initial_matrix, i, j);
            adjugated.values[i][j] *= (i + j) % 2 ? -1 : 1; 
        }
    }

    transpose_matrix(&adjugated, &adjugated_T);

    for(i = 0; i < 3; ++i){
        for(j = 0; j < 3; ++j){
            inverted_matrix->values[i][j] = adjugated_T.values[i][j] / abs_det;
        }
    }

}



/*===Part2===*/

typedef struct vector_s{
    double x, y, z;
} vector;


void scan_vector(vector *v){
    scanf("%lf", &(v->x));
    scanf("%lf", &(v->y));
    scanf("%lf", &(v->z));
}

void print_vector(vector v){
    printf("%.4lf %.4lf %.4lf", v.x, v.y, v.z);
}

void cross_product(vector vec_1, vector vec_2, vector *output_vec){
    output_vec->x = vec_1.y * vec_2.z - vec_1.z * vec_2.y;
    output_vec->y = vec_1.x * vec_2.z - vec_1.z * vec_2.x;
    output_vec->z = vec_1.x * vec_2.y - vec_1.y * vec_2.x;
}

double dot_product(vector vec_1, vector vec_2){
    return vec_1.x * vec_2.x + vec_1.y * vec_2.y + vec_1.z * vec_2.z;
}

double magnitude(vector v){
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

double find_orthogonal(vector vec_1, vector vec_2, vector *output_vec){
    double dot_p;

    cross_product(vec_1, vec_2, output_vec);
    dot_p = dot_product(vec_1, vec_2);

    return acos(dot_p / (magnitude(vec_1) * magnitude(vec_2)));
}



/*===Part3===*/

typedef struct third_order_polynomial_s{
    double coefficients[4];
} third_order_polynomial;

typedef struct polynomial_s{
    double coefficients[7];
    char constant;
    double integral_value;
} polynomial;




polynomial third_order_polynomial_product(third_order_polynomial p1, third_order_polynomial p2){
    polynomial result;
    int i, j;

    for(i = 0; i < 7; ++i)
        result.coefficients[i] = 0;

    for(i = 0; i < 4; ++i)
        for(j = 0; j < 4; ++j)
            result.coefficients[i+j] += p1.coefficients[i] * p2.coefficients[j];

    return result;
}

polynomial get_integral(third_order_polynomial p1, third_order_polynomial p2, int a, int b){
    polynomial result;
    polynomial product;
    int i, j;
    double integral_val = 0;

    product = third_order_polynomial_product(p1, p2);

    for(i = 0; i < 7; ++i){
        result.coefficients[i] = product.coefficients[i] / (i + 1);
    }

    result.constant = 'c';


    for(i = 0; i < 7; ++i){
        integral_val += result.coefficients[i] * pow(b, i + 1);
        integral_val -= result.coefficients[i] * pow(a, i + 1);
    }

    result.integral_value = integral_val;

    return result;
}


int main(){

    //part1
    matrix my_matrix, my_matrix_inverse;
    printf("Enter nine values fo matrix:\n");
    scan_matrix(&my_matrix);
    print_matrix(my_matrix);

    inverse_matrix(&my_matrix, &my_matrix_inverse);
    print_matrix(my_matrix_inverse);

    //part2
    vector my_vector_1, my_vector_2, orth;
    double angle;

    printf("Enter 3 values for vector 1:\n");
    scan_vector(&my_vector_1);

    printf("Enter 3 values for vector 2:\n");
    scan_vector(&my_vector_2); 

    angle = find_orthogonal(my_vector_1, my_vector_2, &orth);

    printf("Angle between vectors is: %.4lf\nOrthagonal vector is:\n", angle);
    print_vector(orth);

    //part3
    third_order_polynomial p1, p2;
    polynomial result;



    return 0;
}