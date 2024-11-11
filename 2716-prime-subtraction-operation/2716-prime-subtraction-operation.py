class Solution:
    def primeSubOperation(self, nums: List[int]) -> bool:
        # sieve of eratosthenes
        isPrime = [True]*1001
        isPrime[0]=isPrime[1]=False
        for i in range (2,int(sqrt(1000)+1)):
            if isPrime[i]:
                for j in range(i*i,1001,i):
                    isPrime[j]=False                        

        n = len(nums)
        
        prev = 0
        for n in nums:
            upperBound = n - prev # non-inclusive
            LargestPrime = 0
            for i in reversed(range (2,upperBound)):
                if isPrime[i]:
                    LargestPrime = i
                    break
            if n-LargestPrime <= prev:
                return False
                
            prev = n - LargestPrime

        return True


