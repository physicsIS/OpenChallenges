program sieve_atkin
implicit none
integer :: n ! Número hasta el cual buscar

logical, allocatable :: is_prime(:)

integer :: x, y, k, i

print *, "dame un primo, por favor: "
read *, n ! lee el límite dado


if ( n < 2) then
	print *, "no hay primos menores que 2"
	stop
end if

! crear array dinámico con n entradas
allocate(is_prime(0:n))
is_prime = .false. ! todos los candidatos inician siendo NO PRIMOS 

! en atkin, se toman desde el inicio como primos el 2 y el 3

if (n >= 2) is_prime(2) = .true.
if (n >= 3) is_prime(3) = .true.


! acá se empiezan a aplicar los filtros cuadráticos
do x = 1, int(sqrt(real(n)))
	do y = 1, int(sqrt(real(n)))

		k = 4 * x ** 2 + y ** 2
		if ( k <= n .and. mod(k, 12) == 1 .or. mod(k, 12) == 5) then
			is_prime(k) = .not. is_prime(k)
		end if

		k = 3 * x ** 2 + y ** 2
		if ( k <= n .and. mod(k, 12) == 7) then
			is_prime(k) = .not. is_prime(k)
		end if

		k = 3 * x ** 2 - y ** 2
		if ( x > y .and. k <= n .and. mod(k, 12) == 11) then
			is_prime(k) = .not. is_prime(k)
		end if
	end do
end do

! acá inicia la discriminación por múltiplos de cuadrados
do i = 5, int(sqrt((real(n))))
	if (is_prime(i)) then
		k = i**2
		do while (k <= n)
			is_prime(k) = .false.
			k = k + i**2
		end do
	end if
end do

! acá se muestran los reusltados

print*, "los primos hasta ", n, "son:"
do i = 2, n
	if (is_prime(i)) print *, i
end do

deallocate(is_prime)

end program sieve_atkin
