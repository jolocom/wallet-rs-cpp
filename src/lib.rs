pub use universal_wallet::{
    contents::{
        Content,
        ContentEntity,
        public_key_info::KeyType,
    },
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
    pub fn new_key(&mut self, key_type: KeyType, key_controller: Option<Vec<String>>)
        -> Result<ContentEntity, String> {
            match self.wallet.new_key(key_type, key_controller) {
                Ok(entity) => Ok(entity),
                Err(e) => Err(e.to_string())
            }
    }
    pub fn import_content(&mut self, content: &Content)
        -> Option<ContentEntity> {
            self.wallet.import_content(content)
        }
    pub fn set_content(&mut self, cref: &str, content: Content)
        -> Option<ContentEntity> {
            self.wallet.set_content(cref, content)
        }
    pub fn get_key(&self, key_ref: &str) -> Option<ContentEntity> {
        self.wallet.get_key(key_ref)
    }
    pub fn get_key_by_controller(&self, controller: &str) -> Option<ContentEntity> {
       self.wallet.get_key_by_controller(controller) 
    }
    pub fn set_key_controller(&mut self, key_ref: &str, controller: &str)
        -> Option<()> {
            self.wallet.set_key_controller(key_ref, controller)
        }
    pub fn get_keys(&self) -> Vec<ContentEntity> {
        self.wallet.get_keys()
    }
    pub fn sign_raw(&self, key_ref: &str, data: &[u8]) -> Result<Vec<u8>, String> {
        match self.wallet.sign_raw(key_ref, data) {
            Ok(signature) => Ok(signature),
            Err(e) => Err(e.to_string())
        }
    }
    pub fn decrypt(&self, key_ref: &str, data: &[u8], aad: Option<&[u8]>)
        -> Result<Vec<u8>, String> {
            match self.wallet.decrypt(key_ref, data, aad) {
                Ok(decrypted) => Ok(decrypted),
                Err(e) => Err(e.to_string())
            }
        }
    pub fn ecdh_key_agreement(&self, key_ref: &str, key: &[u8])
        -> Result<Vec<u8>, String> {
            match self.wallet.ecdh_key_agreement(key_ref, key) {
                Ok(shared_secret) => Ok(shared_secret),
                Err(e) => Err(e.to_string())
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

