require "osl"

class PieceTest < Test::Unit::TestCase
  def test_new
    assert_not_nil(Osl::Piece.new)
  end

  def test_to_csa
    assert_true(Osl::Piece.new.to_csa.is_a?(String))
  end
end
