// consider the function z = x² + y²
// let's make a database of qtd_elements

qtd_elements = 500

i = 1; //iterator
rand('seed', getdate('s')); //initialize the random number generator
rand('uniform'); // the random number generator should create numbers between 0 and 1
                 //it makes the process faster

while i<=qtd_elements
    x(i) = rand();
    y(i) = rand();
    z(i) = x(i)*x(i) + y(i)*y(i);
    if z(i)<=1 then //just iterate if z(i) < 1
        i = i+1     // z should be less than 1 because tanh function goes until 1
    end
end

matriz_dados = [x y z] // the data matrix have columns x_values, y_values, z_values

dir = "C:\Users\SALA DE AULA\Documents\Assis" // path to save data

write_csv(A,dir + '/data_function.csv') //saving data

// yay! \o/
