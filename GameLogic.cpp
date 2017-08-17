#include "GameLogic.h"


namespace GameLogic
{
  std::shared_ptr<Player> player;
  gameState state;
  namespace Keyboard
  {
    void keyW(keyType type)
    {
      if (type == keyType::PRESS) {
        if (state == gameState::Playing) {
          // adjust velocity in y
          player->setVelocityY(-1.0*player->getMaxVelocity());
        }
      }
      if (type == keyType::RELEASE) {
        if (state == gameState::Playing) {
          // adjust velocity in y
          player->setVelocityY(0);
        }
      }
    }
    void keyA(keyType type)
    {
      if (type == keyType::PRESS) {
        if (state == gameState::Playing) {
          // adjust velocity in x
          player->setVelocityX(-1.0*player->getMaxVelocity());
        }
      }
      if (type == keyType::RELEASE) {
        if (state == gameState::Playing) {
          // adjust velocity in x
          player->setVelocityX(0);
        }
      }
    }
    void keyS(keyType type)
    {
      if (type == keyType::PRESS) {
        if (state == gameState::Playing) {
          // adjust velocity in y
          player->setVelocityY(player->getMaxVelocity());
        }
      }
      if (type == keyType::RELEASE) {
        if (state == gameState::Playing) {
          // adjust velocity in y
          player->setVelocityY(0);
        }
      }
    }

    void keyD(keyType type)
    {
      if (type == keyType::PRESS) {
        if (state == gameState::Playing) {
          // adjust velocity in x
          player->setVelocityX(player->getMaxVelocity());
        }
      }
      if (type == keyType::RELEASE) {
        if (state == gameState::Playing) {
          // adjust velocity in x
          player->setVelocityX(0);
        }
      }
    }
    void keyEsc(keyType type)
    {
      if (type == keyType::PRESS) {
        if (state == gameState::Playing) {
          // open/close menu
        }
      }
    }
    void keySpace(keyType type)
    {
      if (type == keyType::PRESS) {
        if (state == gameState::Playing) {
          // start shooting
        }
      }
      if (type == keyType::RELEASE) {
        if (state == gameState::Playing) {
          // stop shooting

        }
      }
    }

    void handleKeyboardEvent(const std::string& key, keyType type)
    {
      if (key == "W") { keyW(type); }
      if (key == "A") { keyA(type); }
      if (key == "S") { keyS(type); }
      if (key == "D") { keyD(type); }
      if (key == "Esc") { keyEsc(type); }
      if (key == "Space") { keySpace(type); }
    }
  }

  void initialise(std::shared_ptr<Player> _player)
  {
    state = gameState::Playing;
    player = _player;
    
  }

  namespace Collision
  {
    
  }
}



