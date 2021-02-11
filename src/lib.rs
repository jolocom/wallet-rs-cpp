use universal_wallet::{
    locked::LockedWallet,
    unlocked::UnlockedWallet,
};

pub struct CppUnlockedWallet {
    wallet: UnlockedWallet
}

pub struct CppLockedWallet {
    wallet: LockedWallet
}

impl CppUnlockedWallet {
    pub fn new(id: &str) -> Self {
        Self {
            wallet: UnlockedWallet::new(id)
        }
    }
    pub fn lock(&self, key: &[u8]) -> Result<CppLockedWallet, String> {
        match self.wallet.lock(key) {
            Ok(w) => Ok(CppLockedWallet {
                wallet: w
            }),
            Err(e) => Err(e.to_string())
        }
    }
}

impl CppLockedWallet {
    pub fn new(id: &str, ct: &[u8]) -> Self {
        Self {
            wallet: LockedWallet::new(id, ct.to_vec())
        }
    }
    pub fn unlock(&self, key: &[u8]) -> Result<CppUnlockedWallet, String> {
        match self.wallet.unlock(key) {
            Ok(w) => Ok(CppUnlockedWallet {
                    wallet: w
                }),
            Err(e) => Err(e.to_string())
        }
    }
}

