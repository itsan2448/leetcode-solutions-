class Solution:
    def primeSubOperation(self, nums: List[int]) -> bool:
        # sieve of eratosthenes
        isPrime = [True]*1001
        isPrime[0]=isPrime[1]=False
        for i in range (2,int(sqrt(1000)+1)):
            if isPrime[i]:
                for j in range(i*i,1001,i):
                    isPrime[j]=False                                
        
        Primes=[0,0] # lets store the last big prime
        for i in range(2,max(nums)):
            if isPrime[i]:
                Primes.append(i)
            else :
                Primes.append(Primes[i-1])

        n = len(nums)

        prev = 0
        for n in nums:
            upperBound = n - prev # non-inclusive
            LargestPrime = Primes[upperBound - 1]
            if n-LargestPrime <= prev:
                return False
                
            prev = n - LargestPrime

        return True